/* 
    file name: myhello.c
    author: 2020114658_LEE Yoon Seo
    datetime: 2021-10-21 20:12
    description: get user input and print message that in curse animation (250ms) using handler
 */

#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10

// set user input message length BUFSIZ
char user_input[BUFSIZ];
char blank[BUFSIZ];

int dir = 1;
int pos = LEFTEDGE;


void print_user_input(int);
int set_ticker(int);

int main() {

    printf("Please enter message: ");
    fflush(stdout);

    // get user input message
    scanf("%s", user_input);

    initscr();
    clear();

    // use timer (signal handler)
    signal(SIGALRM, print_user_input);

    // set the initial value and make it repeat every 0.25 seconds
    if (set_ticker(250) == -1) {
        perror("set_ticker");
    }

    else {
        // print the user_input and wait
        while (1) {
            move(ROW, pos);
            addstr(user_input);
            move(LINES - 1, COLS - 1);
            refresh();
            pause();
        }
    }
}

// If there is a signal, set the blank then update pos and dir
void print_user_input(int signum) {

    int i;

    // set the blank for the message length
    for (i = 0; i < strlen(user_input); i++) {
        blank[i] = ' ';
    }

    move(ROW, pos);
    addstr(blank);

    pos += dir;

    if (pos >= RIGHTEDGE)
        dir = -1;

    if (pos <= LEFTEDGE)
        dir = 1;
}