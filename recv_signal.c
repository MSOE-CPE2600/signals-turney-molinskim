/**
 * File: recv_signal.c
 * Modified by: Marshall Molinski
 * 
 * Brief summary of program: Registers a handler for SIGUSR1
 *                           that prints a value sent with the 
 *                           signal.
 */
 #include <signal.h>
 #include <stdio.h>
 #include <unistd.h>

 void handle_signal(int sig, siginfo_t *info, void *context){
    printf("Received value: %d\n", info->si_value.sival_int);
 }

 int main(){
    struct sigaction action;
    action.sa_sigaction=handle_signal;
    action.sa_flags=SA_SIGINFO;

    sigaction(SIGUSR1, &action, NULL);
    printf("Receiver running. PID: %d\n", getpid());
    while(1) pause();
    return 0;
 }