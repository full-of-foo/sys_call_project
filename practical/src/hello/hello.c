/* A system call that can say hello world

Authors - Liam Allen
        - Anthony Troy
*/
#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage long sys_hello(const char *test)
{
    printk(KERN_ALERT "Hello %s\n", test);
    return 0;
}
