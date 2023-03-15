obj-m := proc_jiffies.o

all: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	sudo dmesg -C
	sudo insmod proc_jiffies.ko
	sleep 3s
	sudo rmmod proc_jiffies.ko
	dmesg
