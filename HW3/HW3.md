# HW3

### Question 1

> When trying to run the program null, a segmentation fault occured

![1773441060276](image/HW3/1773441060276.png)


### Question 2

> After recompiling with "-g" flag for more info and running with gdp, gdp shows a segmentation fault occured

![1773441176848](image/HW3/1773441176848.png)


### Question 3

> After running the program with valgrind, it gives a report of what occured when running the program, as well as heap, leak, and error summaries.
>
> This report says that in invalid read was attempted and where.
> It also says how the process was terminated (due to a segmentation fault signal).

![1773441349887](image/HW3/1773441349887.png)


### Question 4

> When running the program with gdb, no errors are shown.

![1773441631380](image/HW3/1773441631380.png)

> However when running with valgrind, it picks up that the heap memory wasn't freed before exiting. 

![1773441642664](image/HW3/1773441642664.png)


### Question 5

> When the program for question 5 is run, the program exits normally.

![1773441963431](image/HW3/1773441963431.png)

> However, when run with valgrind, it notifies of an invalid write of size 4 due to no bytes after the block size of 400 that was allocated. i.e. an out of bounds write.

![1773442012837](image/HW3/1773442012837.png)



### Question 6

> When the program is run, a garbage value is printed

![1773442118776](image/HW3/1773442118776.png)

> When run with valgrind, it notifies of an invalid read due to no bytes in a block that was free'd. 

![1773442149420](image/HW3/1773442149420.png)



### Question 7

> For this case, no tool is needed, the compiler notifies that a pointer that wasn't the original pointer allocated tried to be freed.

![1773442244018](image/HW3/1773442244018.png)
