#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>
#include <interface/if.h>
#include <common/stringutility.h>

namespace uc {

#define MAX_FILE_PATH 512			//定义最大文件路径长度
#define MAX_FILE_NAME_LEN 256		//最大文件名长度

/* 判断一个字符串是否为一个目录名 */
bool CFileUtility::isDirectory(const char* str)
{
	assert(str);
	struct stat statBuf;
	if (::stat(str, &statBuf) < 0)
		return false;
	return (statBuf.st_mode & S_IFDIR) == S_IFDIR;
}
/* 清空一个目录,删除该目录下的所有文件包括子目录, 尾端匹配*/
bool CFileUtility::emptyDirectoryByEndName(const char *szDir, const char *szEndName)
{
	SStatInfo statInfo;
	if (!CFileUtility::stat(szDir, &statInfo))
		return false;			// Fail if the directory does not exist
	CDirectoryScan dirScan(szDir);
	bool allDeleted = true;		// Did we delete everything?
	int32_t len = strlen(szEndName);

	size_t buflen = strlen(szDir) + 2 + MAX_FILE_NAME_LEN;
	char *item = static_cast<char *>(malloc(buflen));
	while (dirScan.readNext()) {
		bool okToDelete = false;
		const char *szFileName = dirScan.getName();
		int32_t nFileLen = strlen(szFileName);
		if (nFileLen > len && strncmp(szFileName + nFileLen - len, szEndName, len) == 0)
			okToDelete = true;
		if (okToDelete) {
			sprintf(item, "%s%s%s", szDir, getPathSeparator(), dirScan.getName());
			if (!dirScan.isDirectory()) 
				allDeleted = CFileUtility::deleteFile(item) && allDeleted;
		}
	}
	free(item);
	return allDeleted;
}

/************************************************************************/
/* Linux文件系统函数                                                    */
/************************************************************************/
#ifndef _WIN32

/* 文件重新命名 */
bool CFileUtility::rename(const char *szCurrentFileName, const char *szNewFileName)
{
	bool rc = false;
    
	struct stat64 stbuf;
	if (lstat64(szNewFileName, &stbuf) != 0) {
		rc = (::rename(szCurrentFileName, szNewFileName) == 0);
	}
	return rc;
}
/* stat一个文件,获得的文件信息将被填充到StatInfo对象中 */
bool CFileUtility::stat(const char *szFileName, SStatInfo *pStatInfo)
{
	bool rc = false;

	struct stat64 stbuf;
	int lstatres;

	do {
		lstatres = lstat64(szFileName, &stbuf);
	} while (lstatres == -1 && errno == EINTR);
	if (lstatres == 0) {
		pStatInfo->m_error = SStatInfo::Ok;
		pStatInfo->m_isRegular = S_ISREG(stbuf.st_mode);
		pStatInfo->m_isDirectory = S_ISDIR(stbuf.st_mode);
		pStatInfo->m_nSize = static_cast<int64_t>(stbuf.st_size);
		pStatInfo->m_modifiedTime = stbuf.st_mtime;
		rc = true;
	} else {
		if (errno == ENOENT)
			pStatInfo->m_error = SStatInfo::FileNotFound;
		else
			pStatInfo->m_error = SStatInfo::Unknown;
	}

	return rc;
}
/* 创建一个目录 */
bool CFileUtility::makeDirectory(const char *szName)
{
	return (mkdir(szName, 0775) == 0);
}
/* 删除一个目录 */
bool CFileUtility::removeDirectory(const char *szName)
{
	return (rmdir(szName) == 0);
}
/* 得到当前目录 */
char *CFileUtility::getCurrentDirectory(void)
{
	char *szCurrentDir = new char[MAX_FILE_PATH + 1];

	if (getcwd(szCurrentDir, MAX_FILE_PATH) == NULL) {
		delete [] szCurrentDir;
		szCurrentDir = NULL;
	}
	return szCurrentDir;
}
/* 设定当前目录 */
bool setCurrentDirectory (const char *szPathName) {
	return (chdir(szPathName) == 0);
}
/* 删除一个文件 */
bool CFileUtility::deleteFile(const char *szFileName)
{
	return (unlink(szFileName) == 0);
}
/* 清空一个目录,删除该目录下的所有文件包括子目录 */
bool CFileUtility::emptyDirectory(const char *szDir, const char *szKeepFile)
{
	SStatInfo statInfo;
	if (!CFileUtility::stat(szDir, &statInfo))
		return false;			// Fail if the directory does not exist
	CDirectoryScan dirScan(szDir);
	bool allDeleted = true;		// Did we delete everything?

	size_t buflen = strlen(szDir) + 2 + MAX_FILE_NAME_LEN;
	char *item = static_cast<char *>(malloc(buflen));
	while (dirScan.readNext()) {
		bool okToDelete = true;
		if (strcmp(dirScan.getName(), ".") == 0 || strcmp(dirScan.getName(), "..") == 0 || (szKeepFile != NULL && strcmp(dirScan.getName(), szKeepFile) == 0))
			okToDelete = false;
		if (okToDelete) {
			sprintf(item, "%s%s%s", szDir, getPathSeparator(), dirScan.getName());
			if (dirScan.isDirectory()) {
				if (!emptyAndRemoveDirectory(item))
					allDeleted = false;
			} else
				allDeleted = CFileUtility::deleteFile(item) && allDeleted;
		}
	}
	free(item);
	return allDeleted;
}

/* 创建一个目录,如果目录已经存在,则返回成功 */
void CFileUtility::makeDirIfNotPresentOrExit(const char *szName)
{
	SStatInfo statInfo;

	if(CFileUtility::stat(szName, &statInfo)) {
		if(statInfo.m_isDirectory)
			return;
		fprintf(stderr, "%s is not a directory\n", szName);
		exit(1);
	}

	if(statInfo.m_error != SStatInfo::FileNotFound) {
		fprintf(stderr, "Could not stat %s: %s\n", szName, strerror(errno));
		exit(1);
	}

	if(!CFileUtility::makeDirectory(szName)) {
		fprintf(stderr, "Could not mkdir(\"%s\", 0775): %s\n", szName, strerror(errno));
		exit(1);
	}
}

#else
/************************************************************************/
/* Windows文件系统函数                                                  */
/************************************************************************/

/* 重新命名一个文件或目录,只有当当前文件和新文件的路径在同一个硬盘上才能执行操作,如果新名字已经存在则失败 */
bool CFileUtility::rename(const char *szCurrentFileName, const char *szNewFileName)
{
	return (::MoveFile(szCurrentFileName, szNewFileName)) ? true : false;
}
/* 创建一个目录 */
bool CFileUtility::makeDirectory(const char *szName)
{
	return (::CreateDirectory(szName, NULL) != 0);
}
/* 删除一个目录 */
bool CFileUtility::removeDirectory(const char *szName)
{
	return (::RemoveDirectory(szName) != 0);
}
/* 得到当前目录 */
char *CFileUtility::getCurrentDirectory(void)
{
	char *szCurrentDir = new char [MAX_FILE_PATH + 1];
	if(::GetCurrentDirectory(MAX_FILE_PATH, szCurrentDir) == 0) {
		delete[] szCurrentDir;
		szCurrentDir = NULL;
	}
	return szCurrentDir;
}
/* stat一个文件,获得的文件信息将被填充到StatInfo对象中 */
bool CFileUtility::stat(const char *szFileName, SStatInfo *pStatInfo)
{
	struct stat stbuf;
	int statres;

	statres = ::stat(szFileName, &stbuf);
	if (statres == 0) {
		pStatInfo->m_error = SStatInfo::Ok;
		pStatInfo->m_isRegular = ((_S_IFREG & stbuf.st_mode) != 0);
		pStatInfo->m_isDirectory = ((_S_IFDIR & stbuf.st_mode) != 0);
		pStatInfo->m_nSize = (int64_t)stbuf.st_size;
		pStatInfo->m_modifiedTime = stbuf.st_mtime;
		return true;
	}
	else {
		if (errno == ENOENT) {
			pStatInfo->m_error = SStatInfo::FileNotFound;
		}
		else {
			pStatInfo->m_error = SStatInfo::Unknown;
		}
	}

	return false;
}
/* 删除一个文件 */
bool CFileUtility::deleteFile (const char *szFileName)
{
	return (DeleteFile(szFileName) != 0);
}
/* 清空一个目录,删除该目录下的所有文件包括子目录 */
bool CFileUtility::emptyDirectory(const char *szDir, const char *szKeepFile)
{
	SStatInfo statInfo;
	if (!CFileUtility::stat(szDir, &statInfo))
		return false;			// Fail if the directory does not exist
	CDirectoryScan dirScan(szDir);
	bool allDeleted = true;		// Did we delete everything?

	size_t buflen = strlen(szDir) + 2 + MAX_FILE_NAME_LEN;
	char *item = static_cast<char *>(malloc(buflen));
	while (dirScan.readNext()) {
		bool okToDelete = true;
		if (strcmp(dirScan.getName(), ".") == 0 || strcmp(dirScan.getName(), "..") == 0 || (szKeepFile != NULL && strcmp(dirScan.getName(), szKeepFile) == 0))
			okToDelete = false;
		if (okToDelete) {
			sprintf(item, "%s%s%s", szDir, getPathSeparator(), dirScan.getName());
			if (dirScan.isDirectory()) {
				if (!emptyAndRemoveDirectory(item))
					allDeleted = false;
			} else
				allDeleted = CFileUtility::deleteFile(item) && allDeleted;
		}
	}
	free(item);
	return allDeleted;
}
/* 创建一个目录,如果目录已经存在,则返回成功 */
void CFileUtility::makeDirIfNotPresentOrExit(const char *szName)
{
	SStatInfo statInfo;

	char *szDirName = strdup(szName);
	if (szDirName[strlen(szDirName)-1] == '/' || szDirName[strlen(szDirName)-1] == '\\') {
		szDirName[strlen(szDirName)-1] = '\0';
	}
	if(CFileUtility::stat(szDirName, &statInfo)) {
		if(statInfo.m_isDirectory) {
			free(szDirName);
			return;
		}
		fprintf(stderr, "%s is not a directory\n", szDirName);
		exit(1);
	}

	if(statInfo.m_error != SStatInfo::FileNotFound) {
		fprintf(stderr, "Could not stat %s: %s\n", szDirName, strerror(errno));
		exit(1);
	}

	if(!CFileUtility::makeDirectory(szDirName)) {
		fprintf(stderr, "Could not mkdir(\"%s\", 0775): %s\n", szDirName, strerror(errno));
		exit(1);
	}
	free(szDirName);
}
#endif

#ifndef _WIN32
/************************************************************************/
/* Linux下CDirectoryScan类的实现                                        */
/************************************************************************/
/* 构造函数 */
CDirectoryScan::CDirectoryScan(const char *szSearchPath)
{
    m_szSearchPath = strdup(szSearchPath);
	m_bStatRun = false;
	m_isDirectory = false;
	m_isRegular = false;
	m_statName = NULL;
	m_statFilenameP = NULL;
	m_dir = NULL;
	m_dp = NULL;

	m_dir = opendir(szSearchPath);
	m_statName = new char[MAX_FILE_NAME_LEN + 1];  // Include null
	strcpy(m_statName, szSearchPath);
	strcat(m_statName, "/");
	m_statFilenameP = &m_statName[strlen(m_statName)];
}
/* 希构函数 */
CDirectoryScan::~CDirectoryScan(void)
{
	if (m_dir != NULL) {
		closedir(m_dir);
		m_dir = NULL;
	}
	delete []m_statName;
	free(m_szSearchPath);
}
/* 读取目录下的内容 */
bool CDirectoryScan::readNext(void)
{
	bool rc = false;

	m_bStatRun = false;
	if (m_dir != NULL) {
		m_dp = readdir(m_dir);
		rc = m_dp != NULL;
	}

	return rc;
}
/* 是否为目录 */
bool CDirectoryScan::isDirectory(void)
{
	if (!m_bStatRun)
		doStat();
	return m_isDirectory;
}
/* 是否为规则路径 */
bool CDirectoryScan::isRegular(void)
{
	if (!m_bStatRun)
		doStat();

	return m_isRegular;
}
/* 取得路径名 */
const char *CDirectoryScan::getName(void)
{
	assert(m_dp != NULL);
	return static_cast<const char *>(m_dp->d_name);
}
/* 执行unix下的stat */
void CDirectoryScan::doStat(void)
{
    struct stat64 stbuf;

    assert(m_dp != NULL);
   
    strcpy(m_statFilenameP, m_dp->d_name);
    if (lstat64(m_statName, &stbuf) == 0) {
        m_isRegular = S_ISREG(stbuf.st_mode);
        m_isDirectory = S_ISDIR(stbuf.st_mode);
    } else {
        printf("lstat failed for [%s], errno: %d, %s\n", m_dp->d_name, errno, strerror(errno));
        m_isRegular = false;
        m_isDirectory = false;
    }
    m_bStatRun = true;
}

#else
/************************************************************************/
/* Windows下CDirectoryScan类的实现                                      */
/************************************************************************/
CDirectoryScan::CDirectoryScan(const char *szSearchPath)
{
    m_szSearchPath = strdup(szSearchPath);
	m_findHandle = INVALID_HANDLE_VALUE;
	m_first = true;
	m_pSearch = NULL;
	generateSearchPath();
}

CDirectoryScan::~CDirectoryScan ()
{
	if(m_findHandle != INVALID_HANDLE_VALUE) {
		FindClose(m_findHandle);
		m_findHandle = NULL;
	}

	if (m_pSearch != NULL) {
		delete(m_pSearch);
		m_pSearch = NULL;
	}
	free(m_szSearchPath);
}

void CDirectoryScan::generateSearchPath(void)
{
	m_pSearch = new char[strlen(m_szSearchPath) + 1 + 2];
	strcpy(m_pSearch, m_szSearchPath);

	if (!(endsWith(m_pSearch, '/') || endsWith(m_pSearch, '\\'))) {
		strcat(m_pSearch, "\\*");
	}
	else {
		if(endsWith(m_pSearch, '/') || endsWith(m_pSearch, '\\')) {
			strcat(m_pSearch, "*");
		}
	}
}

bool CDirectoryScan::endsWith (char *szString, char character)
{
	size_t len = strlen(szString);
	if (len > 0) {
		return (szString[len-1] == character);
	}

	return false;
}

bool CDirectoryScan::readNext(void)
{
	if(m_first) {
		m_first = false;
		m_findHandle = FindFirstFile(m_pSearch, &m_findFileData);
		return (m_findHandle != INVALID_HANDLE_VALUE);
	}
	else {
		return FindNextFile(m_findHandle, &m_findFileData) != FALSE;
	}

	return false;
}

bool CDirectoryScan::isDirectory(void)
{
	assert(m_findHandle != INVALID_HANDLE_VALUE);
	return (m_findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

bool CDirectoryScan::isRegular(void)
{
	return !isDirectory();
}

const char *CDirectoryScan::getName(void)
{
	assert(m_findHandle != INVALID_HANDLE_VALUE);
	return (const char *)m_findFileData.cFileName;
}

#endif

int32_t
CFileOtherUtility::is_dir(const char * filename)
{
	struct stat buff;  
	if (lstat(filename, &buff) < 0)
		return 0;
	return S_ISDIR(buff.st_mode);
}

int32_t
CFileOtherUtility::is_file(const char *filename)
{
	return !is_dir(filename) && (access(filename, 0) != -1);
}

int32_t
CFileOtherUtility::lockfile(int32_t fd)
{
	struct flock lock;

	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_type = F_WRLCK;
	return (fcntl(fd, F_SETLK, &lock));
}

int32_t
CFileOtherUtility::already_running(const char *pidfile, int32_t lockmode)
{
	int		fd;
	char	buf[16];
	fd = open(pidfile, O_RDWR|O_CREAT, lockmode);
	if (fd < 0)
	{
		//CLog::Error("CFileOtherUtility: Can't open pid file %s: %s", pidfile, strerror(errno));
		exit(1);
	}
	if (lockfile(fd) < 0)
	{
		if (errno == EACCES || errno == EAGAIN)
		{
			close(fd);
			return 1;
		}
		//CLog::Error("CFileOtherUtility: Can't lock %s: %s", pidfile, strerror(errno));
		exit(1);
	}

	int sign;
	if ((sign = ftruncate(fd, 0)) != 0)
	{
		//CLog::Error("CFileOtherUtility: Error: %d", sign);
		exit(1);
	}
	sprintf(buf, "%ld", (long)getpid());
	if ((sign = write(fd, buf, strlen(buf))) < 0)
	{
		//CLog::Error("CFileOtherUtility: Error: %d", sign);
		exit(1);
	}
	return 0;
}

}

//////////////END
