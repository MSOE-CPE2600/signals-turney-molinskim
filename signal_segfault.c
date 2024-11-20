/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Marshall Molinski
 * 
 * Brief summary of modifications: Demonstrates how to intercept the
 *                                 SIGSEGV signal using a signal handler
 */


#include <stdio.h>
#include <signal.h>

void segfault_handler(int sig) {
    printf("Segmentation fault caught: %d\n", sig);
}

int main () {
    signal(SIGSEGV, segfault_handler);
    // Declare a null pointer
    int *ptr = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *ptr);

    // Return to exit the program
    return 0;
}