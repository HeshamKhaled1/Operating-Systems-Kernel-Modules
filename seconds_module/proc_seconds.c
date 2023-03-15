#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>
#include <asm/param.h>

#define BUFFER_SIZE 128
#define PROC_NAME "seconds"

ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

static const struct proc_ops my_fops = {
	.proc_read = proc_read,
};


unsigned long FSNOI=0;

int proc_init(void)
{
	proc_create(PROC_NAME, 0666, NULL, &my_fops);
	FSNOI=jiffies;
	return 0;
}

void proc_exit(void)
{
	remove_proc_entry(PROC_NAME, NULL);
}

ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
	int rv = 0;
	char buffer[BUFFER_SIZE];
	static int completed = 0;
	
	if(completed) 
	{
		completed = 0;
		return 0;
	}

	completed = 1;
	
	rv = sprintf(buffer, "no of seconds =%lu seconds\n", (jiffies - FSNOI) / HZ);
	copy_to_user(usr_buf, buffer, rv);

	return rv;
}

module_init(proc_init);
module_exit(proc_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Seconds Module");
MODULE_AUTHOR("Hesham Khaled Salah <represented to dr.Ahmed Amer>");
