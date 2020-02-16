#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sched.h>
#include <linux/fs.h>
#include <sys/types.h>
#include <errno.h>

int main() {
    FILE* myFile = fopen("myreallycoolfile.txt","a");

    unsigned int fd = fileno(myFile);

    long int shoutout = syscall(335);
    printf("System call sys_newcall returned %ld\n", shoutout);

    long int shoutout1 = syscall(__NR_get_tag, 1);
    printf("System call sys_get_tag returned %ld\n", shoutout1);

    long int shoutout2 = syscall(__NR_set_tag, 1, 0);
    printf("System call sys_set_tag returned %ld\n", shoutout2);

    long int shoutout3 = syscall(__NR_get_class, fd);
    printf("System call sys_get_class returned %ld\n", shoutout3);

    long int shoutout4 = syscall(__NR_set_class, fd, 1);
    printf("System call sys_set_class returned %ld\n", shoutout4);

    return 0;
}
