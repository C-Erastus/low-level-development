#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Erastus");
MODULE_DESCRIPTION("Hello world driver");

/* Initializaton function that gets called when the module isloaded*/
static int __init hello_world_init(void)
{
	printk(KERN_INFO "Hello, world!\n");
	return 0; /* This indicates suceess */
}

/* Cleanup function that gets called when the module is unloaded */
static void __exit hello_world_exit(void)
{
	printk(KERN_INFO "Hello, world dirver exit\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);
