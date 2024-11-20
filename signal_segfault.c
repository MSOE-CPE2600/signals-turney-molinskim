/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Marshall Molinski
 * 
 * Brief summary of modifications:
 */


#include <stdio.h>
#include <signal.h>

void segfault_handler(int sig) {
    printf("Segmentation fault caught: %d\n", sig);
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}