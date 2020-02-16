#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sched.h>

int main() {
    long int shoutout = syscall(335);
    printf("System call sys_newcall returned %ld\n", shoutout);

    long int shoutout1 = syscall(__NR_get_tag, 1);
    printf("System call sys_get_tag returned %ld\n", shoutout1);

    long int shoutout2 = syscall(__NR_set_tag, 1, 2);
    printf("System call sys_set_tag returned %ld\n", shoutout2);

    return 0;
}
