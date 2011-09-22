#ifndef __UC_STRING_UTILITY_H__
#define __UC_STRING_UTILITY_H__

#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <functional>

namespace uc
{

struct str_map_compare :public std::binary_function<std::string,std::string,bool> 
{
	bool operator()(std::string str1,std::string str2) const
	{
		return strcmp(str1.c_str(), str2.c_str()) < 0;
	}
};

typedef std::map<std::string,std::string,str_map_compare>  StringMap;

/* Delete leading and trailing spaces from a string */
std::string stripSpaces(std::string strVal);

void splitString(const std::string& input, const std::string& delim, std::vector<std::string>& output);

void findReplaceStringAll(std::string &str,const std::string& strOldValue, std::string& strNewValue);

void replaceStringAllDistinct(std::string& str,const std::string& old_value,const std::string& new_value);

void URLDecode(char *word);

bool is_a_num(const char *p);

char toHex(const char &x);

std::string URLEncode(const char* lpszData);

int encodeConvert(const char* from, const char* to, const char *pszBuffer, size_t uBufferLen, char *pszNewBuffer, size_t &uNewBufferLen);

char* trim(char *pStr);

int32_t ntolower(char *pInput, uint32_t uInputLen, uint32_t uLimitNum);

}

#endif
