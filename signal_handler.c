/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Marshall Molinski
 * 
 * Brief summary of modifications: Register a signal handler
 *                                 and handle signals like SIGINT
 *                                 without exiting the program.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal(int sig) {
    if(sig == SIGINT) {
    printf("\nCaught SIGINT. Send SIGKILL to terminate.\n");
    }
}

int main() {

    // Register for the signal
    struct sigaction action;
    action.sa_handler = handle_signal;//set handler function
    action.sa_flags = 0;//no special flags
    sigaction(SIGINT, &action, NULL);//register the signal handler

    printf("Running signal handler. PID: %d\n", getpid());
    printf("CTRL+C to send SIGINT (will not terminate the program).\n");
    printf("CTRL+\\ or send SIGKILL to terminate the program.\n");

    // infinite loop that waits for signals
    while(1) {
        pause();//wait
        if (signal(SIGQUIT, SIG_DFL) == SIG_DFL) {
            printf("Caught SIGQUIT. Exiting program.\n");
            break;
        }
    }

    return 0;
}