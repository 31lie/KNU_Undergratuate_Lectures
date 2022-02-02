/* 
    file name: ticker_demo.c
    author: 2020114658_LEE Yoon Seo
    datetime: 2021-10-21 20:00
    description: demonstrates use of interval timer to generate regular signals, which are in turn caught and used to count down
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>

void countdown(int);
int set_ticker(int);

int main() {

    signal(SIGALRM, countdown);

    if (set_ticker(500) == -1) {
        perror("set_ticker");
    }

    else {
        while (1) {
            pause();
        }
    }

    return 0;
}

void countdown(int signum) {

    static int num = 10;
    printf("%d ..", num--);
    fflush(stdout);

    if (num < 0) {
        printf("DONE!\n");
        exit(0);
    }
}