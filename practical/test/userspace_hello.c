/* Program that issues a system call to the kernel space and prints
   hello world

Authors - Liam Allen
        - Anthony Troy
*/

//Gives access to the system calls
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Call the hello word system call, in this case
     it is passed two parameters, the system call number,
     and the string we wish to print.
  */
  syscall(349, "World!!!\n");
  return 0;
}
