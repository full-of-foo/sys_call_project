/* A system call that will display the current process name,
ID, parent process name and parent ID.

Authors - Liam Allen
        - Anthony Troy
*/
#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage void sys_datastructs(void)
{
  struct task_struct *task;
  printk(KERN_ALERT "Current process name is: %s\n", current->comm);
  printk(KERN_ALERT "Current PID: %i\n", current->pid);
  printk(KERN_ALERT "Parent process name: %s\n", current->parent->comm);
  printk(KERN_ALERT "Parent process PID: %i\n", current->parent->pid);

  for_each_process(task)
    pr_info("Command:%s     |PID: [%d] |State:%ld |Priority: %d \n",
            task->comm, task->pid, task->state, task->prio);

	return 0;
}
