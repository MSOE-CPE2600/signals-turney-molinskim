/**
 * File: signal_alarm.c
 * Modified by: Marshall Molinski
 * 
 * Brief summary of program: Simple program that sets a 5 second alarm
                             and the signal is received by the signal handler
 */
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void alarm_handler(int sig) {
    printf("Alarm received: %d\n", sig);

}

int main(){
    signal(SIGALRM, alarm_handler);
    alarm(5);// 5 second alarm
    pause();//wait for sig
    return 0;
}