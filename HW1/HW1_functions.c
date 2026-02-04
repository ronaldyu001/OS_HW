#include <unistd.h> //provides system call wrapper functions for (MECHANISMS)
#include <fcntl.h> //provides (POLICY) flags and options for mechanisms
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>


void question_7(){

    int pipe_1[2];  //array to hold pipe references
    pipe(pipe_1);   //stores two file descriptors that point to the pipe heads

    pid_t pid_1 = fork(); //create child

    // CHILD 1
    if(pid_1 == 0){
        close(pipe_1[0]);   //close pipe 1 read head
        char message[100] = "Hi child 2, I'm child 1!";
        write(pipe_1[1], message, sizeof(message)-1);   //write to pipe 1
        printf("\nMessage sent to Child 2\n");
        close(pipe_1[1]);   //close pipe 1 write head
        _exit(0);   //end child process
    }

    pid_t pid_2 = fork();   //create child

    // CHILD 2
    if(pid_2 == 0){
        int status;
        waitpid(pid_1, &status, 0);
        close(pipe_1[1]);    //close pipe 1 write head
        char message[100];
        size_t n = read(pipe_1[0], message, sizeof(message)-1); //read message from pipe 1
        message[n] = '\0';
        printf("\nMessage received from Child 1: %s\n", message);
        close(pipe_1[0]);     //close pipe 1 read head
        _exit(0);   //end child process
    }

    close(pipe_1[0]);   //close pipe
    close(pipe_1[1]);
    return;


    // NOTE that pipe reference arrays are duplicated on fork, but point to the same pipe.
    // Closing a pipe reference only ends that proccess's ability to use the closed head.
    // All file descriptor references to the pipe must be closed to close the pipe.
}


void question_6(){
    pid_t pid = fork();

    //CHILD
    if(pid == 0){
        close(STDOUT_FILENO); //close standard output
        printf("hello!"); //try print
    }

    //PARENT
    else{
        printf("oh hey!");
    }

    return;


    // NOTE if standard output is closed, prints don't work.
    // However, no errors get thrown for attempting a print.
}


void question_5(){
    printf("\nParent Process Started\n");
    pid_t pid = fork(); //parent: child pid, child: 0

    //CHILD
    if(pid == 0){
        printf("\nChild Process Started\n");
        sleep(2);
        printf("\nChild Process Finished\n");
        wait(NULL);
        // _exit(5);
    }

    //PARENT
    else{
        int status;
        pid_t dummy_pid = 1234;
        waitpid(pid, &status, 0); //get status
        printf("\nParent Process Finished. Child status: %d\n", status);
    }
    
    fflush(stdout);
    return;

    // NOTE waitpid same as wait except can specify the pid and blocking behavior.
    // Blocking - 0: block until child finishes. Other args available too.
    // Good for more control over wait behavior.
}


void question_4(){
    printf("\nParent Process Started\n");
    pid_t pid = fork(); //parent: child pid, child: 0

    //CHILD
    if(pid == 0){
        printf("\nChild Process Started\n");
        sleep(2);
        printf("\nChild Process Finished\n");
        wait(NULL);
        // _exit(5);
    }

    //PARENT
    else{
        int status;
        wait(&status); //get status
        printf("\nParent Process Finished. Child status: %d\n", status);
    }
    
    
    fflush(stdout);
    return;

    // NOTE the child exits with status 0 if no errors. 
    // If manually exited with a number other than 0, exit status != 0.
    // A wait inside a child doesn't seem to do anything. Must have children to wait.
}


void question_3(){
    pid_t pid = fork(); //parent: child pid, child: 0

    //CHILD
    if(pid == 0){
        char *args[] = {"ls", "-l", NULL};
        execve("/bin/ls", args, NULL);
    }

    fflush(stdout);
    return;

    // NOTE all exec commands replace the current process with a new program.
    //
    // execl: accepts a list of args, uses exact path for program
    // execle: accepts a list of args, custom environment, uses exact path for program
    // execlp: accepts a list of args, searches current process path for program
    // execv: accepts a vector of args, uses the exact path for program
    // execvp: accepts a vector of args, searches current process path for program
    // execvP: accepts a vector of args, searches specified path search for program
    // execve: accepts a vector of args, custom environment, uses the exact path for program

}


void question_2(){
    pid_t pid = fork(); //fork returns child pid to parent, and 0 to child
    char *process_type = (pid==0) ? "Child":"Parent" ; //use pid to check if parent or child
    char buffer[100];


    //CHILD
    if(pid == 0){ 
        int file_descriptor = open("temp.txt", O_CREAT | O_RDWR | O_TRUNC, 0644); //create temp file for read/write if DNE with write permissions. Empties on open.
        printf("\n[CHILD] opened and erased file\n");
        ssize_t bytes_read = read(file_descriptor, buffer, sizeof(buffer)-1); //read file contents to buffer
        buffer[bytes_read] = '\0'; //turn into C string
        char *text_to_write = "I am the child.";
        printf("\n[CHILD] writing content to file: %s\n", text_to_write);
        lseek(file_descriptor, 0, SEEK_END); //set the seek offset to size of file plus offset bytes (0) to append text.
        write(file_descriptor, text_to_write, strlen(text_to_write)); //write text to file
        lseek(file_descriptor, 0, SEEK_SET); //reset the seek offset to offset bytes (0)
        bytes_read = read(file_descriptor, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';
        printf("\n[CHILD] temp file contents after write: %s\n", buffer);
    }
    
    //PARENT
    else{
        int file_descriptor = open("temp.txt", O_CREAT | O_RDWR | O_TRUNC, 0644); //create temp file for read/write if DNE with write permissions. Empties on open.
        printf("\n[PARENT] opened and erased file\n");
        ssize_t bytes_read = read(file_descriptor, buffer, sizeof(buffer)-1); //read file contents to buffer
        buffer[bytes_read] = '\0'; //turn into C string
        char *text_to_write = "I am the Parent.";
        printf("\n[PARENT] writing content to file: %s\n", text_to_write);
        lseek(file_descriptor, 0, SEEK_END); //set the seek offset to size of file plus offset bytes (0) to append text.
        write(file_descriptor, text_to_write, strlen(text_to_write)); //write text to file
        lseek(file_descriptor, 0, SEEK_SET); //reset the seek offset to offset bytes (0)
        bytes_read = read(file_descriptor, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';
        printf("\n[PARENT] temp file contents after write: %s\n", buffer);
    }
    
    // NOTE that the parent and child open, read, and write to the file separately.
    // There is no guarantee for an arbitrary order of operations.
    // Final contents of file depends on order of operations. Race condition on file.

    return;
}


void question_1(){
    int x = 100;
    pid_t pid = fork(); //fork returns child pid to parent, and 0 to child
    char *process_type = (pid==0) ? "Child":"Parent" ; //use pid to check if parent or child
    
    //CHILD
    if(pid == 0){
        printf("\nParent or Child: %s\nx value: %d\n\n", process_type, x);
        x = 50; //child updates x
        printf("\nParent or Child: %s\nx value: %d\n\n", process_type, x);
    }

    //PARENT
    else{ 
        printf("\nParent or Child: %s\nx value: %d\n\n", process_type, x);
        x = 75; //parent updates x
        printf("\nParent or Child: %s\nx value: %d\n\n", process_type, x);
    }

    // NOTE that the child prints x as 100 when run. 
    // This shows that a separate copy of x is created for the child process.
    
    return;
}