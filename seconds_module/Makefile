obj-m += proc_seconds.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

task:
	sudo insmod proc_seconds.ko
	sleep 3s
	cat /proc/jiffies
	sudo rmmod proc_seconds.ko
