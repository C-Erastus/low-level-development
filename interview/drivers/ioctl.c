#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

/* This macro defines the custom IOCTL command to set a message in the kernel module.
 * It specifies the IOCTL command number, it's direction, and the type of data being
 * transferred
 */
#define IOCTL_SET_MSG _IOR('k', 1, char *)
#define DEVICE_NAME "ioctl_example"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Erastus");
MODULE_DESCRIPTION("Kernel module using IOCTL");
MODULE_VERSION("0.1");

static int major_number; 
static char message[256] = "Hello, ioctl!";
static int message_len;

static int device_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Opening the device\n");
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "releasing the device\n");
	return 0; 
}

/* This function is called when a user-space program invokes an IOCTL command 
 * on the device file associated with this module. It handles the 'IOCTL_SET_MSG'
 * command by copying the message from user space to kernel space
 */
static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
	char *temp;
	int err = 0; 

	switch (ioctl_num) {
		case IOCTL_SET_MSG:
			temp = (char *)ioctl_param;

			err = copy_from_user(message, temp, message_len);
			if (err != 0)
				return -EFAULT;

			message_len = strlen(message) + 1; 
			break;
		default:
			return -ENOTTY; /*Inappropriate ioctl for device */
	}
	
	return 0; 
}

/* This structure defines the file operations supported by the device. In this example
 * it includes functions for opening, releasing, and handling IOCTL commands
 */
static struct file_operations fops = 
{
	.open = device_open,
	.release = device_release,
	.unlocked_ioctl = device_ioctl,
};

static int __init ioctl_init(void)
{
	/*register_chrdev: This function registier a character device with the kernel*/
	major_number = register_chrdev(0, DEVICE_NAME, &fops);
	if (major_number < 0){
		printk(KERN_INFO "Failed to register a major number\n");
		return major_number;
	}
	printk(KERN_INFO "Registered correctly with maor number %d\n", major_number);
	message_len = strlen(message) + 1; /* Initialize message length */
	return 0;
}

static void __exit ioctl_exit(void)
{
	/*unregister_chrdev: This function unregisters the character device when
	 * the module is unloaded 
	 */
	unregister_chrdev(major_number, DEVICE_NAME);
	printk(KERN_INFO "module exit!\n");
}

module_init(ioctl_init);
module_exit(ioctl_exit);
