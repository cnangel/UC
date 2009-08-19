/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @Filename: ucrun.c
 * @Description: 
 * @Author: cnangel
 * @Version: 1.0.0
 * @Time: 2009/07/29 16:51:41
 */


#include <stdio.h>
#include <uc.h>

#define MAXSPACE 1024

int main(int argc, char *argv[])
{
	const char *str = "Apple Company and Mircosoft Company IS corRIVal.";
	int flag = 1;
	if (argc == 2 || argc == 3) {
		str = argv[1];
		if (argc == 3) flag = atoi(argv[2]);
	}
	char *reply = (char *)malloc(MAXSPACE);
	memset(reply, 0, MAXSPACE);
	helloworld(str, reply, flag);
	printf("%s\n", reply);
	free(reply);
	return 0;
}

