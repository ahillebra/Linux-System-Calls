#include <unistd.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <stdio.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <asm/unistd.h>
#include <linux/fs.h>
#include <errno.h>

long get_tag(pid_t PID){
	return syscall(__NR_get_tag, PID);
	}

long set_tag(pid_t PID, int newvalue) {
	return syscall(__NR_set_tag, PID, newvalue);
	}

long get_class(FILE* fd){
	if(fd == NULL){
		errno = -1;
		return -1;
	}
	else{
	long int fdd = fileno(fd);
	return syscall(__NR_get_class, fdd);
	}
}

long set_class(FILE* fd, int newvalue) {
	if(fd == NULL){
		errno = -1;
		return -1;
	}
	else{
	long int fdd = fileno(fd);
	return syscall(__NR_set_class, fdd, newvalue);
	}
}
