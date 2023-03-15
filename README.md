# Operating-Systems-Kernel-Modules
## First Task
Kernel module that creates a /proc file named /proc/jiffies that reports the current value of jiffies when /proc/jiffies file is read, such as with the command:
cat /proc/jiffies
Be sure to remove /proc/jiffies when the module is removed.

## Second Task
Kernel module that creates a /proc file named /proc/seconds that reports the number of elapsed seconds since the kernel module was loaded.
This will involve using the value of jiffies as well as the HZ rate.
When a user enters the command:
cat /proc/seconds
your kernel module will report the number of seconds that have elapsed since the kernel module was first loaded.
Be sure to remove /proc/seconds when the module is removed.
