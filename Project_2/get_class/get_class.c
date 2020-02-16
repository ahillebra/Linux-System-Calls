#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/cred.h>
#include <linux/file.h>
#include <asm/unistd.h>
#include <linux/fs.h>

SYSCALL_DEFINE1(get_class, unsigned int, fd) {

	int ret; //set ret
	struct fd f; //create the fd
	f = fdget(fd); //locate the fd
	if(f.file){ //if the fd is validly assigned to a file
		printk("THIS IS MY GET_CLASS CALL AND HERE'S THE VALUE OF CLASSIFICATION: ");
		printk("%d\n", f.file->f_inode->classification);
		fdput(f);
		ret = f.file->f_inode->classification; //set the return value
		return ret;
	}
	return -1; //error occurred
}
