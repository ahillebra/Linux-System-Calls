#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/cred.h>

SYSCALL_DEFINE2(set_tag, int, PID, int, newvalue) {

//	if (geteuid() != 0){
//	return -1;
//	}

	//const struct cred *cred = current_cred();

	int euid = from_kuid_munged(current_user_ns(), current_euid());

	//if (cred->uid.val != 0){
	if(euid != 0){
	return -1;
	}

	if (find_task_by_vpid(PID) == NULL){
	return -1;
	}

	if (newvalue < 0){
	return -1;
	}

	find_task_by_vpid(PID)->tag = newvalue;
	printk("THIS IS MY SET_TAG SYSTEM CALL\n");
	return find_task_by_vpid(PID)->tag;
}
