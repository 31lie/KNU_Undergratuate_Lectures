/*
    file: waitdemo3.c
    author: 2020114658_LEE Yoon Seo
    datetime: 2021-11-11 19:32
    description: print messages using handler
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

#define DELAY 5



int main() {

    int newpid;
    void child_code();
    void parent_code();

    printf("before: mypid is %d\n", getpid());

    if ((newpid = fork()) == -1)
        perror("fork");
    else if (newpid == 0)
        child_code(DELAY);
    else
        parent_code(newpid);
    
    return 0;
}


void child_code(int delay) {

    printf("child %d here. will sleep for %d seconds\n", getpid(),delay);
    sleep(delay);
    printf("child done. about to exit\n");
    exit(17);
}

void parent_code(int childpid) {
    
    // delcare handler
    void handler(int);

    // execute handler when SIGCHLD signal occurs
    signal(SIGCHLD, handler);
    
    // print messages util child process finish.
    while(1) {
        printf("parent is busy...\n");
        sleep(1);
    }   
}

void handler(int singum) {

    // print child status

    int wait_rv;
    int child_status;
    int high_8, low_7, bit_7;

    wait_rv = wait(&child_status);

    high_8 = child_status >> 8;
    low_7 = child_status & 0x7F;
    bit_7 = child_status & 0x80;
    printf("status: exit = %d, sig = %d, core = %d\n", high_8, low_7, bit_7);

    exit(0);
}