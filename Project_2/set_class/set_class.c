#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/cred.h>
#include <linux/file.h>
#include <asm/unistd.h>
#include <linux/fs.h>
#include <linux/highuid.h>

SYSCALL_DEFINE2(set_class, int, fd, int, newvalue) {

	int ret; //init return value
	struct fd f; //create fd
	int euid = from_kuid_munged(current_user_ns(), current_euid()); //init access
	f = fdget(fd); //get the file

	if (euid != 0){ //if access is not ok
	return -1; //error
	}

	if(f.file){ //if it's a file
		f.file->f_inode->classification = newvalue; //set the new value
		fdput(f); //close it
		ret = newvalue; //set return value
		printk("THIS IS MY SET_CLASS SYSTEM CALL AND HERE'S THE VALUE OF CLASSIFICATION: \n"); //for testing
		printk("%d\n", f.file->f_inode->classification); //for testing
		return ret;
	}

	printk("SET_CLASS RAN, BUT DIDN'T WORK"); //for testing
	return -1;
}
