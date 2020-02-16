#include <linux/syscalls.h>
#include <linux/kernel.h>

SYSCALL_DEFINE0(newcall) {
	printk("THIS IS MY SYSTEM CALL\n");
	return 0;
}
