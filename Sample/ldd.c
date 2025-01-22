#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sainadth Pagadala");
MODULE_DESCRIPTION("Sample Kernel Module");


/* 
    When module is injected/inserted (insERTmodULE -insmod) init() function will be executed
    return 0 on Success
    return non zero on failure
*/
static int sainadth_module_init(void){
    printk("Hello, world!!, from sainadth kernel module \n");
    return 0;
}

/* 
    When module is ejected/removed (rEmOVEmodULE -rmmod) exit() function will be executed
*/
static void sainadth_module_exit(void){
    printk("Good Bye!!, from sainadth kernel module \n");
}

module_init(sainadth_module_init);
module_exit(sainadth_module_exit);