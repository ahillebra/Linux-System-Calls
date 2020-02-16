#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sched.h>
#include <linux/fs.h>
#include <sys/types.h>
#include <errno.h>
#include "tagcalls.h"

int main() {
	int currentProcessPid = getpid();
	set_tag(currentProcessPid, 22);
	FILE* myFile = fopen("myreallycoolfile.txt","a");
	unsigned int fd;

	//fd = fileno(myFile);

	long int shoutout3 = get_class(myFile);
	printf("System call sys_get_class returned %ld\n", shoutout3);

	long int shoutout4 = set_class(myFile, 33);
	printf("System call sys_set_class returned %ld\n", shoutout4);

	return 0;
}
