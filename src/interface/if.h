#ifndef __UC_FILE_UTILITY_H__
#define __UC_FILE_UTILITY_H__

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <sys/stat.h>

#ifndef  _WIN32
#include <unistd.h>
#include <dirent.h>
#else
#include <windows.h>
#include <direct.h>
#endif

namespace uc {

struct SStatInfo;		//前置声明

class CFileUtility
{

public:
	/* 重新命名一个文件或目录,只有当当前文件和新文件的路径在同一个硬盘上才能执行操作,如果新名字已经存在则失败 */
	static bool rename(const char *szCurrentFileName, const char *szNewFileName);
	/* 创建一个目录 */
	static bool makeDirectory(const char *szName);
	/* 删除一个目录 */
	static bool removeDirectory(const char *szName);
	/* 得到当前目录 */
	static char *getCurrentDirectory(void);
	/* 设定当前目录,WARNING! Will not set drive letter on Windows */
	static bool setCurrentDirectory (const char *szPathName);
	/* 删除一个文件 */
	static bool deleteFile(const char *szName);
	/* stat一个文件,获得的文件信息将被填充到StatInfo对象中 */
	static bool stat(const char *szFileName, SStatInfo *pStatInfo);
	/* 删除一个目录,即使它不为空 */
	static bool emptyAndRemoveDirectory(const char *szDir) {
		return (emptyDirectory(szDir) && removeDirectory(szDir));
	}
	/* 清空一个目录,删除该目录下的所有文件包括子目录 */
	static bool emptyDirectory(const char *szDir, const char *szKeepFile = NULL);
	/* 清空一个目录,删除该目录下的所有文件包括子目录, 尾端匹配*/
	static bool emptyDirectoryByEndName(const char *szDir, const char *szEndName);
	/* 创建一个目录,如果目录已经存在,则返回成功 */
	static void makeDirIfNotPresentOrExit(const char *szName);
	/* 返回路径分割字符,unix上为"/",win32为"\" */
	static const char *getPathSeparator(void) {return "/";};
	/* 确认路径是否为绝对路径 */
	static bool isAbsolutePath(const char *szPath);
	/* 判断一个字符串是否为一个目录名 */
	static bool isDirectory(const char* str);
};

/* 该结构体保存了经过函数stat返回的信息 */
struct SStatInfo
{
	enum StatError {
		Ok,           //!< ok
		Unknown,      //!< unknown error
		FileNotFound  //!< file not found error
	};
	StatError m_error;		//可能的错误代码
	bool m_isRegular;		//是否为一个规则的文件,只要当m_error等于Ok时该变量才有效
	bool m_isDirectory;		//是否为一个目录
	int64_t m_nSize;	//文件大小
	time_t m_modifiedTime;	//文件修改时间
};

/* 该对象枚举某个目录下所有的内容 */
class CDirectoryScan
{
private:
	CDirectoryScan(const CDirectoryScan&);
	CDirectoryScan& operator= (const CDirectoryScan&);

private:
	char *m_szSearchPath;			//搜索路径
#ifndef _WIN32
    bool m_bStatRun;		//stat是否在运行
    bool m_isDirectory;		//是否为一个目录
    bool m_isRegular;		//是否为规则目录
    char *m_statName;		//文件或目录名
    char *m_statFilenameP;	//拼接文件
    DIR *m_dir;
    struct dirent *m_dp;	
#else
	WIN32_FIND_DATA m_findFileData;
	HANDLE m_findHandle;
	bool m_first;
	char *m_pSearch;
#endif

private:
#ifndef _WIN32
	/* 执行linux下的stat */
    void doStat(void);
#else
	/* 字符串结束判断 */
	bool endsWith (char *szString, char character);
	/* 生成正确的字符串路径 */
	void generateSearchPath(void);
#endif

public:
	/* 构造函数 */
	CDirectoryScan(const char *szPath);
	/* 析构函数 */
	~CDirectoryScan(void);
	/* 返回路径 */
	const char *getSearchPath(void) { return m_szSearchPath; }
	/* 读该目录中下一个目录入口,如果成功,可以通过isDirectory, isRegular调用来获得目录信息 */
	bool readNext(void);
	/* 是否为目录 */
	bool isDirectory(void);
	/* 是否为一个规则的目录 */
	bool isRegular(void);
	/* 文件名 */
	const char *getName(void);
};

class CFileOtherUtility
{

public:
	/**
	 * check whether is directory
	 * @param filename a string of the filename
	 * @return 1 if directory return 1, else return 0
	 */
	static int32_t is_dir(const char * filename);
	/**
	 * check whether is file 
	 * @param filename a string of the filename
	 * @return 1 if file exists, else return 0
	 */
	static int32_t is_file(const char *filename);
	/**
	 * lock a file
	 * @param fd a integer of the file description
	 * @return 0 if success, locking if failed.
	 */
	static int32_t lockfile(int32_t fd);
	/**
	 * check a programme whether is already running
	 * @param pidfile a string of the pid file
	 * @param lockmode a integer of the lock mode, for example:
	 *                 - S_IRUSR
	 *                 - S_IWUSR
	 *                 - S_IRGRP
	 *                 - S_IROTH
	 * @return 0 if success, exit if failed.
	 */
	static int32_t already_running(const char *pidfile, int32_t lockmode);

};

};

#endif
