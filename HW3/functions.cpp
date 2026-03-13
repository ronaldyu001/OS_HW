#include "functions.h"
#include <iostream>




// ----- Question 1 -----

// First, write a simple program called null.c that creates a pointer to an integer, sets it
// to NULL, and then tries to dereference it. Compile this into an executable called null.
// What happens when you run this program?

void q1(){
	int x = 25;				// integer
	int* x_pointer = &x;			// pointer to integer
	x_pointer = NULL;			// set pointer to NULL
	std::cout << *x_pointer << std::endl;	// print the dereferenced pointer

	return;
}



// ----- Question 2 -----

// Next, compile this program with symbol information included (with the -g flag).
// Doing so, let’s put more information into the executable, enabling the debugger to
// access more useful information about variable names and the like. Run the program
// under the debugger by typing gdb null and then, once gdb is running, typing run.
// What does gdb show you?

void q2(){
        
        return;
}

// ----- Question 3 -----

// Finally, use the valgrind tool on this program. We’ll use the memcheck tool that is a
// part of valgrind to analyze what happens. Run this by typing in the following:
// valgrind --leak-check=yes null. What happens when you run this? Can you interpret
// the output from the tool?

void q3(){
        
        return;
}

// ----- Question 4 -----

// Write a simple program that allocates memory using malloc() but forgets to free it
// before exiting. What happens when this program runs? Can you use gdb to find any
// problems with it? How about valgrind (again with the --leak-check=yes flag)?

void q4(){
        
	int x = 25;
	int* x_pointer = (int*) malloc(sizeof(int));

        return;
}

// ----- Question 5 -----

// Write a program that creates an array of integers called data of size 100 using
// malloc; then, set data[100] to zero. What happens when you run this program?
// What happens when you run this program using valgrind? Is the program correct?

void q5(){

	int* data = (int*) malloc(100 * sizeof(int));
	data[100] = 0;

        return;
}



// ----- Question 6 -----

// Create a program that allocates an array of integers (as above), frees them, and
// then tries to print the value of one of the elements of the array. Does the program
// run? What happens when you use valgrind on it?

void q6(){

        int* data = (int*) malloc(100 * sizeof(int));	// allocate array
        free(data);					// free the array
	std::cout << data[0] << std::endl;		// try to print first element of array
	
	
	return;
}



// ----- Question 7 -----

// Now pass a funny value to free (e.g., a pointer in the middle of the array you
// allocated above). What happens? Do you need tools to find this type of problem?

void q7(){
        int* data = (int*) malloc(100 * sizeof(int));   // allocate array
	free(data + 49);                                 // free value in the middle of the array

        return;
}






