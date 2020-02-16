#ifndef TAGCALLS_H_
#define TAGCALLS_H_

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <linux/types.h>

long get_tag(pid_t PID);
long set_tag(pid_t PID, int newvalue);

#endif
