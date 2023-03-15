#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int jiffies_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "jifiies = %llu\n", get_jiffies_64());
	return 0;
}

static int __init proc_jiffies_init(void)
{
	proc_create_single("jiffies", 0, NULL, jiffies_proc_show);
	return 0;
}

static void __exit proc_jiffies_cleanup(void)
{
	remove_proc_entry("jiffies", NULL);
}
module_init(proc_jiffies_init);
module_exit(proc_jiffies_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hesham Khaled Salah");
MODULE_DESCRIPTION("module to add jiffies file into /proc <presented to dr.Ahmed Amer>");
