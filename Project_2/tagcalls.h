#ifndef TAGCALLS_H_
#define TAGCALLS_H_

#include <unistd.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <stdio.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <asm/unistd.h>
#include <linux/fs.h>
#include <sys/file.h>

long get_tag(pid_t PID);
long set_tag(pid_t PID, int newvalue);
long get_class(FILE* fd);
long set_class(FILE* fd, int newvalue);

#endif
