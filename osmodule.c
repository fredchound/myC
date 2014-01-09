#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static void print_task(void)
{
	struct task_struct *task;
	int i = 0;
	for_each_process(task){
		printk(KERN_INFO "Task %d PID %d\n",i, task->pid);
		i++;
	}

}


int osmodule_init(void)
{
	printk(KERN_INFO "Loading module. \n");

	print_task();

	return 0;
}

void osmodule_exit(void)
{
	printk(KERN_INFO "Removing module.\n");

}


module_init(osmodule_init);
module_exit(osmodule_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("OS MODULE");
MODULE_AUTHOR("F C ND");

