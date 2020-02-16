#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/cred.h>


SYSCALL_DEFINE1(get_tag, int, PID) {

	//if (geteuid() != 0){
        //return -1;
        //}

	const struct cred *cred = current_cred();

        if ((cred->uid.val != 0) && (current->pid != PID)){
        return -1;
        }

//	if (current_cred() != 0){
//	return -1;
//	}

        if (find_task_by_vpid(PID) == NULL){
        return -1;
        }

        printk("THIS IS MY GET_TAG SYSTEM CALL\n");
        return find_task_by_vpid(PID)->tag;
}
