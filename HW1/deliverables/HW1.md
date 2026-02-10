

### Question 1

The child prints x as 100 initially when run. This shows that a separate copy of x is created for the child process. COW creates a copy of the original data (only relevant part) for a process on write, but not read.

![1770690205606](image/HW1/1770690205606.png)


### Question 2

Both the parent and child can access the file descriptor. But open, read, and write to the file separately. There is no guarantee for an arbitrary order of operations. Final contents of file depends on order of operations. Race condition on file.

![1770690266821](image/HW1/1770690266821.png)


### Question 3

All exec commands replace the current process with a new program. Useful for fine control when "exec"ing a process with a program. Allows for environment injection.

> execl: accepts a list of args, uses exact path for program
> execle: accepts a list of args, custom environment, uses exact path for program
> execlp: accepts a list of args, searches current process path for program
> execv: accepts a vector of args, uses the exact path for program
> execvp: accepts a vector of args, searches current process path for program
> execvP: accepts a vector of args, searches specified path search for program
> execve: accepts a vector of args, custom environment, uses the exact path for program [rest of execs wrappers of this one]

![1770690300996](image/HW1/1770690300996.png)


### Question 4

The child exits with status 0 if no errors. If manually exited with a number other than 0, exit status != 0. A wait inside a child doesn't seem to do anything. No children to wait for.

![1770690364296](image/HW1/1770690364296.png)


### Question 5

waitpid same as wait except can specify the pid and blocking behavior. Blocking - 0: block until child finishes. Other args available too. Good for more control over wait behavior.

![1770690364296](image/HW1/1770690364296.png)


### Question 6

If standard output is closed, prints don't work. However, no errors get thrown for attempting a print.

![1770690536804](image/HW1/1770690536804.png)

> In the screenshot above, only the parent process printed. The child process didn't print because standard output was closed.


### Question 7

Pipe reference arrays are duplicated on fork, but point to the same pipe. Closing a pipe reference only ends that proccess's ability to use the closed head. All file descriptor references to the pipe must be closed to close the pipe.

![1770690562324](image/HW1/1770690562324.png)
