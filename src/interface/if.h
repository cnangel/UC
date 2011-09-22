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

struct SStatInfo;		//ǰ������

class CFileUtility
{

public:
	/* ��������һ���ļ���Ŀ¼,ֻ�е���ǰ�ļ������ļ���·����ͬһ��Ӳ���ϲ���ִ�в���,����������Ѿ�������ʧ�� */
	static bool rename(const char *szCurrentFileName, const char *szNewFileName);
	/* ����һ��Ŀ¼ */
	static bool makeDirectory(const char *szName);
	/* ɾ��һ��Ŀ¼ */
	static bool removeDirectory(const char *szName);
	/* �õ���ǰĿ¼ */
	static char *getCurrentDirectory(void);
	/* �趨��ǰĿ¼,WARNING! Will not set drive letter on Windows */
	static bool setCurrentDirectory (const char *szPathName);
	/* ɾ��һ���ļ� */
	static bool deleteFile(const char *szName);
	/* statһ���ļ�,��õ��ļ���Ϣ������䵽StatInfo������ */
	static bool stat(const char *szFileName, SStatInfo *pStatInfo);
	/* ɾ��һ��Ŀ¼,��ʹ����Ϊ�� */
	static bool emptyAndRemoveDirectory(const char *szDir) {
		return (emptyDirectory(szDir) && removeDirectory(szDir));
	}
	/* ���һ��Ŀ¼,ɾ����Ŀ¼�µ������ļ�������Ŀ¼ */
	static bool emptyDirectory(const char *szDir, const char *szKeepFile = NULL);
	/* ���һ��Ŀ¼,ɾ����Ŀ¼�µ������ļ�������Ŀ¼, β��ƥ��*/
	static bool emptyDirectoryByEndName(const char *szDir, const char *szEndName);
	/* ����һ��Ŀ¼,���Ŀ¼�Ѿ�����,�򷵻سɹ� */
	static void makeDirIfNotPresentOrExit(const char *szName);
	/* ����·���ָ��ַ�,unix��Ϊ"/",win32Ϊ"\" */
	static const char *getPathSeparator(void) {return "/";};
	/* ȷ��·���Ƿ�Ϊ����·�� */
	static bool isAbsolutePath(const char *szPath);
	/* �ж�һ���ַ����Ƿ�Ϊһ��Ŀ¼�� */
	static bool isDirectory(const char* str);
};

/* �ýṹ�屣���˾�������stat���ص���Ϣ */
struct SStatInfo
{
	enum StatError {
		Ok,           //!< ok
		Unknown,      //!< unknown error
		FileNotFound  //!< file not found error
	};
	StatError m_error;		//���ܵĴ������
	bool m_isRegular;		//�Ƿ�Ϊһ��������ļ�,ֻҪ��m_error����Okʱ�ñ�������Ч
	bool m_isDirectory;		//�Ƿ�Ϊһ��Ŀ¼
	int64_t m_nSize;	//�ļ���С
	time_t m_modifiedTime;	//�ļ��޸�ʱ��
};

/* �ö���ö��ĳ��Ŀ¼�����е����� */
class CDirectoryScan
{
private:
	CDirectoryScan(const CDirectoryScan&);
	CDirectoryScan& operator= (const CDirectoryScan&);

private:
	char *m_szSearchPath;			//����·��
#ifndef _WIN32
    bool m_bStatRun;		//stat�Ƿ�������
    bool m_isDirectory;		//�Ƿ�Ϊһ��Ŀ¼
    bool m_isRegular;		//�Ƿ�Ϊ����Ŀ¼
    char *m_statName;		//�ļ���Ŀ¼��
    char *m_statFilenameP;	//ƴ���ļ�
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
	/* ִ��linux�µ�stat */
    void doStat(void);
#else
	/* �ַ��������ж� */
	bool endsWith (char *szString, char character);
	/* ������ȷ���ַ���·�� */
	void generateSearchPath(void);
#endif

public:
	/* ���캯�� */
	CDirectoryScan(const char *szPath);
	/* �������� */
	~CDirectoryScan(void);
	/* ����·�� */
	const char *getSearchPath(void) { return m_szSearchPath; }
	/* ����Ŀ¼����һ��Ŀ¼���,����ɹ�,����ͨ��isDirectory, isRegular���������Ŀ¼��Ϣ */
	bool readNext(void);
	/* �Ƿ�ΪĿ¼ */
	bool isDirectory(void);
	/* �Ƿ�Ϊһ�������Ŀ¼ */
	bool isRegular(void);
	/* �ļ��� */
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
