/**
 * File: signal_sigaction.c
 * Modified by: Marshall Molinski
 * 
 * Brief summary of program: Demonstrates sigaction() system call
 *                           For signal handling.
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigusr1(int sig, siginfo_t *info, void *context){
    printf("SIGUSR1 received from PID: %d\n", info->si_pid);
}
int main(){
    struct sigaction action;
    action.sa_sigaction = handle_sigusr1;
    action.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &action, NULL);
    printf("waiting for SIGUSR1... (PID: %d)\n", getpid());

    while(1) pause();//wait
    return 0;
}