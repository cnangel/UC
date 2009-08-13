/**
 * Copyright(c) 2009 Alibaba Company, All Rights Reserved.
 * 
 * @Filename: t1.c
 * @Description: 
 * @Author: cnangel
 * @Version: 1.0.0
 * @Time: 2009/06/08 13:14:21
 */


#include <string.h>
int main(char** argv){
	char name[64];
	char score[3];
	memset(name, '\0',sizeof(name));
	strcpy(name, "Tony");
	printf("%s\n", name);
	printf("%d\n", strlen(name));
	memset(score, '\0', sizeof(score));
	strcpy(score,"100");
	printf("%s\n", name);
	printf("%d\n", strlen(name));
	printf("%d\n", strlen(score));
	printf("%s\n", score);
	system("PAUSE");
}
