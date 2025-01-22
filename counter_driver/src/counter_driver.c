#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#define PROC_FILENAME "virtual_counter"

static int counter = 0;
static char proc_data[16];
static DEFINE_MUTEX(counter_lock);

static ssize_t my_proc_read(struct file *file, char __user *buffer, size_t count, loff_t *offset) {
    char msg[16];
    int len;

    mutex_lock(&counter_lock);
    len = snprintf(msg, sizeof(msg), "%d\n", counter);
    mutex_unlock(&counter_lock);

    return simple_read_from_buffer(buffer, count, offset, msg, len);
}

static ssize_t my_proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *offset) {
    if (count > sizeof(proc_data) - 1) {
        return -EINVAL;
    }

    if (copy_from_user(proc_data, buffer, count)) {
        return -EFAULT;
    }

    proc_data[count] = '\0';

    mutex_lock(&counter_lock);
    if (strcmp(proc_data, "inc\n") == 0) {
        counter++;  // Increment counter
        printk(KERN_INFO "Counter incremented: %d\n", counter);
    } else if (strcmp(proc_data, "dec\n") == 0) {
        counter--;  // Decrement counter
        printk(KERN_INFO "Counter decremented: %d\n", counter);
    } else if (strcmp(proc_data, "reset\n") == 0) {
        counter = 0;  // Reset counter
        printk(KERN_INFO "Counter reset: %d\n", counter);
    } else if (sscanf(proc_data, "set %d", &counter) == 1) {
        printk(KERN_INFO "Counter set to: %d\n", counter);
    } else {
        mutex_unlock(&counter_lock);
        return -EINVAL;
    }
    mutex_unlock(&counter_lock);

    return count;
}

static const struct proc_ops my_proc_ops = {
    .proc_read = my_proc_read,
    .proc_write = my_proc_write,
};

static int __init my_module_init(void) {
    if (!proc_create(PROC_FILENAME, 0666, NULL, &my_proc_ops)) {
        printk(KERN_ERR "Failed to create /proc/%s\n", PROC_FILENAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "Module loaded: /proc/%s created\n", PROC_FILENAME);
    return 0;
}

static void __exit my_module_exit(void) {
    remove_proc_entry(PROC_FILENAME, NULL);
    printk(KERN_INFO "Module unloaded: /proc/%s removed\n", PROC_FILENAME);
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sainadth Pagadala");
MODULE_DESCRIPTION("A simple virtual counter module via /proc interface");
