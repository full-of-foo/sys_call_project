/* This program implements a system call in the kernel space that will
display the current process name, ID, parent process name and parent ID.
It will then display all the current processes running on the system
and display the name of the process, its ID, its priority  and its state.
TO find this message you must either run the command "dmesg", or cat the
/var/log/kern.log file. The /var/log/kern.log file requires root permission
to read, so while we could give the user this promission via a system call
, we instead fork a process in userspace that will automatically run
the "dmesg" command which displays the message buffer of the kernel.
From here the user will see all the running processes, and if they wish
to do so, they can kill a process.

Authors - liam.allen5@mail.dcu.ie
        - anthony.troy3@mail.dcu.ie*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int main()
{
  // Variable declarations
  int pid, number, pid_kill;
  // System call takes a singular parameter, the system call number
  syscall(350);
  // Returns a zero to the newly created child process
  pid = fork();
  // Check for failure
  if(pid < 0)
  {
    // Print out an error stream
    fprintf(stderr, "Fork Failed");
    // Close the program
    exit (-1);
  }
  else if(pid == 0)
  {
    /* execlp provides an array of pointers to null-terminated
    strings that represent the argument list available to
    the new program. The first argument should point to
    the filename associated with the file being executed,
    last argument must be NULL */
    execlp("dmesg", "dmesg", NULL);
  }
  else
  {
    // Wait until no more child processes
    wait(NULL);
    printf("Child complete \n");
    // Take user input
    printf("If you would like to Kill a process Please the number: 1\n");
    scanf("%d", &number);
    if(number == 1)
    {
      printf("Please enter the process ID you wish to terminate:\n");
      scanf(" %d", &pid_kill);
      // Use the kill system call to kill process
      kill(pid_kill, SIGKILL);
    }
    else
    {
      printf("Invalid number entry, closing program \n");
    }
  }
  return 0;
}
