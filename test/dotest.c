/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file dotest.c
 * @details 
 * @author cnangel
 * @version 1.0.0
 * @date 2009/07/30 10:50:14
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(char argc, char** argv){
	char name[64];
	char score[4];
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
	system("ls");
}
