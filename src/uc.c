#include "uc.h"
#include "util/nomalize.h"

/* desc must relocate space, otherwise not safe */
int 
helloworld(const char *src, char *desc, int flag)
{
	size_t srcLen = strlen(src);
	if (srcLen == 0) return 1;
	strncpy(desc, src, srcLen);
	strcat(desc, ", hello, world!");
	if (flag == 1) {
		lc(desc, strlen(desc));
	} else if (flag == 0) {
		uc(desc, strlen(desc));
	}
	return 0;
}
