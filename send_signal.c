/**
 * File: send_signal.c
 * Modified by: Marshall Molinski
 * 
 * Brief summary of program:
 */
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
    srand(time(NULL));
    int value = rand() % 100;
    union sigval sv;
    sv.sival_int = value;

    sigqueue(pid, SIGUSR1, sv);
    printf("Sent value : %d\n", value);
    return 0;
}