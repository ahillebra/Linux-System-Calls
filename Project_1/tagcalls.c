#include <unistd.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <stdio.h>

long get_tag(pid_t PID){
	return syscall(__NR_get_tag, PID);
	}

long set_tag(pid_t PID, int newvalue) {
	return syscall(__NR_set_tag, PID, newvalue);
	}
