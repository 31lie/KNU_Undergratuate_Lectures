/* 
    file name: play_again1.c
    author: 2020114658_LEE Yoon Seo
    datetime: 2021-10-14 20:046 *
    description: ask if user wants another transaction
 */

#include <stdio.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"

int get_response(char *);
void set_crmode();
void tty_mode(int);

int main() {
    int response;

    tty_mode(0);                       // save tty mode
    set_crmode();                      // set chr-by-chr mode
    response = get_response(QUESTION); // get some answer
    tty_mode(1);                       // restore tty mode

    return response;
}

int get_response(char *question) {

    char input;
    printf("%s (y/n)?", question);

    while (1) {
        switch (input = getchar()) {
            case 'y':
            case 'Y':
                return 0;
            case 'n':
            case 'N':
            case EOF:
                return 1;
            default:
                printf("\ncannot understand %c, ", input);
                printf("Please type y or n\n");
        }
    }
}


void set_crmode() {

    struct termios ttystate;

    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &ttystate);
}

void tty_mode(int how) {

    static struct termios original_mode;

    if (how == 0)
        tcgetattr(0, &original_mode);
    else
        tcsetattr(0, TCSANOW, &original_mode);
}