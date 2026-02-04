#include <stdio.h>
#include <stdlib.h>
#include "HW1_functions.h"


int main(){

    // define menu
    char menu[] = 
    "\n---- HW1 Menu ----\n"
    "0. Exit\n"
    "1. Question 1\n"
    "2. Question 2\n"
    "3. Question 3\n"
    "4. Question 4\n"
    "5. Question 5\n"
    "6. Question 6\n"
    "7. Question 7\n\n";

    // user input variables
    char buffer[32];
    int choice;

    // print menu and get user choice
    printf("%s", menu);
    printf("User choice: ");
    fgets(buffer, sizeof(buffer), stdin);
    choice = atoi(buffer);
    fflush(stdout);

    // execute user option
    switch (choice)
    {
    case 0:
        return 0;
    case 1:
        question_1();
        break;
    case 2:
        question_2();
        break;
    case 3:
        question_3();
        break;
    case 4:
        question_4();
        break;
    case 5:
        question_5();
        break;
    case 6:
        question_6();
        break;
    case 7:
        question_7();
        break;
    default:
        printf("Invalid menu option: %d", choice);
        break;
    }   


    return 0;
}