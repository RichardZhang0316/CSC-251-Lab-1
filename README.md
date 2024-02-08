Computer Systems II
Program 1
Spring 2024
System Calls vs. Function Calls :
Are system calls more expensive than function calls? Write a simple test
program to compare the "cost" of a simple function call to a simple
system call
(Note: be careful to prevent the optimizing compiler from "optimizing
out" your function calls. Do not compile with optimization on.
•
Explain the difference (if any) between the time required by simple
function* call and simple system call by discussing what work each call
must do be specific.
You should use system calls such as gethrtime ( ) or
gettimeofday ( ) for time measurements. Design your code such that
the measurement overhead is negligible. Also, be aware that timer
values in some systems have limited resolution (e.g., millisecond).
Compare "cost" for the following:
getuid( ) system call
getppid( ) system call
getcwd( ) system call
write( ) system call
read ( ) system call
function foo ( )
int foo(){
return(10);
}
