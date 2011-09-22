#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string>
#include <vector>
#include <iconv.h>
#include <common/stringutility.h>

namespace uc 
{
	/* Delete leading and trailing spaces from a string */
	std::string stripSpaces(std::string strVal)
	{
		char *name = (char*)strVal.c_str();
		char *p, *q;
		/* Skip over leading spaces */
		p = name;
		while(*p && isspace((unsigned char)*p)) p++;
		if(!*p) return std::string("");
		q = p + strlen(p) - 1;
		while((q != p) && isspace((unsigned char)*q)) q--;
		if(p != q) q[1] = 0;
		if(!*p) return std::string("");
		return std::string(p);
	}


	void splitString(const std::string& input, const std::string& delim, std::vector<std::string>& output)
	{
		std::vector<std::string>().swap(output);
		std::string::size_type pos = 0, prev_pos = 0;
		while( ( pos = input.find_first_of( delim, pos) ) != std::string::npos )
		{
			output.push_back( input.substr(prev_pos, pos-prev_pos) );
			prev_pos = ++pos;
		}
		output.push_back(input.substr(prev_pos) );
	}

	void findReplaceStringAll(std::string &str,const std::string& strOldValue, std::string& strNewValue)
	{
		while(true)   
		{   
			std::string::size_type   pos(0);   
			if((pos = str.find(strOldValue,pos)) != std::string::npos)   
				str.replace(pos,strOldValue.length(),strNewValue); 
			else
				break;
		}   
	}


	void replaceStringAllDistinct(std::string& str,const std::string& old_value,const std::string& new_value)
	{
		for(std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length())   
		{
			if(( pos = str.find(old_value,pos)) != std::string::npos)
				str.replace(pos,old_value.length(),new_value);
			else   
				break;
		}
	} 

	char toHex(const char &x) {
		return x > 9 ? x + 55 : x + 48;
	}

	std::string URLEncode(const char* lpszData)
	{
		std::string strResult = "";

		unsigned char* pInTmp = (unsigned char*) lpszData;
		// do encoding
		while (*pInTmp) {
			if (isalnum(*pInTmp))
				strResult += *pInTmp;
			else if (isspace(*pInTmp))
				strResult += '+';
			else {
				strResult += '%';
				strResult += toHex(*pInTmp >> 4);
				strResult += toHex(*pInTmp % 16);
			}
			pInTmp++;
		}
		return strResult;
	}



	void URLDecode(char *word) 
	{ 
		register int i,j; 
		register int len = strlen(word);

		if (word == NULL) {
			return;
		}

		i = 0;
		j = 0;

		for(i = 0, j = 0; i < len; i++)
		{ 
			if(word[i] == '%')
			{ 
				if(word[i+1] >= 'a' && word[i+1] <= 'f')     
					word[j] = word[i+1] - 'a' + 10; 
				else if(word[i+1] >= 'A' && word[i+1] <= 'F') 
					word[j] = word[i+1] - 'A' + 10; 
				else if(word[i+1] >= '0' && word[i+1] <= '9') 
					word[j] = word[i+1] - '0'; 
				else 
				{ 
					word[j] = '%'; 
					word[j+1] = word[i+1]; 
					j += 2; 
					i++; 
					continue; 
				} 
				word[j] *= 16; 
				if(word[i+2] >= 'a' && word[i+2] <= 'f')
					word[j] += word[i+2] - 'a' + 10; 
				else if(word[i+2] >= 'A' && word[i+2] <= 'F')
					word[j] += word[i+2] - 'A' + 10; 
				else if(word[i+2] >= '0' && word[i+2] <= '9')
					word[j] += word[i+2] - '0'; 
				else 
				{ 
					word[j] = '%'; 
					word[j+1] = word[i+1]; 
					word[j+2] = word[i+2]; 
					j += 3; 
					i += 2; 
					continue; 
				} 
				j++; 
				i += 2; 
			} 
			else if(word[i] == '+') 
			{
				word[j++] = ' '; 
			}
			else 
			{ 
				word[j++] = word[i]; 
			} 
		} 
		word[j] = '\0'; 
	} 


	bool is_a_num(const char *p)
	{
		if (*p == '\0')
			return false;
		while(*p != '\0')
			if(!isdigit(*p++))
				return false;

		return true;
	}

	int encodeConvert(const char* from, const char* to, const char *pszBuffer, size_t uBufferLen, char *pszNewBuffer, size_t &uNewBufferLen)
	{
		int32_t ret;
	
		iconv_t cd = NULL;
		cd = iconv_open(to, from);
		if(cd == (iconv_t)-1)
		{
			return -1;
		}
#if _LIBICONV_VERSION >= 0x0108
		int32_t flag = 1;
		ret = iconvctl(cd, ICONV_SET_DISCARD_ILSEQ, &flag);
		if (ret != 0)
		{
			iconv_close(cd);
			return -1;
		}
#endif
		bzero(pszNewBuffer, uNewBufferLen);
	
		char *pOutBuf = pszNewBuffer;
		size_t n = uNewBufferLen;
	
		size_t in_buf_len = uBufferLen;//strlen(pszBuffer);
		char* pInBuf = (char*)pszBuffer;
		ret = iconv(cd, &pInBuf, &in_buf_len, &pOutBuf, &n);
		iconv_close(cd);
		if(ret == -1)
		{
			if(errno == E2BIG)
			{
				printf("[encodeConvert error]: errno == E2BIG\n");
			}
			else if(errno == EILSEQ)
			{
				printf("[encodeConvert error]: errno == EILSEQ\n");
			}
			else if(errno == EINVAL)
			{
				printf("[encodeConvert error]: errno == EINVAL\n");
			}
			return -1;
		}
		uNewBufferLen -= n;
		return 0;
	}

	char* trim(char *pStr)
	{
		if (pStr == NULL)
			return NULL;
		char *p = pStr;
		while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
			p ++;
		pStr = p;
		p = pStr + strlen(pStr) - 1;
		while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
			-- p;
		*(p + 1) = 0;
		return pStr;
	}

	int32_t ntolower(char *pInput, uint32_t uInputLen, uint32_t uLimitNum)
	{
		uint32_t i;
		uint32_t j;
		if (uLimitNum > uInputLen) 
			uLimitNum = uInputLen;
		i = 0;
		j = 0;
		for(; i < uLimitNum; i ++) 
		{
			if (pInput[i] > 'A' && pInput[i] < 'Z')
			{
				pInput[i] = pInput[i] + 32;
				j ++;
			}
		}
		return j;
	}
};


