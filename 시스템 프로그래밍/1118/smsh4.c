/* file name: smsh4.c
 * author: 2020114658_LEE Yoon Seo
 * datetime: 2021-11-18 18:36
 * description: first really useful version after prompting shell
 * this one parses the command line into strings
 * uses fork, exec, wait, and ignores signals
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "smsh.h"
#include "varlib.h"

#define DFL_PROMPT "ᐕ > "

int main() {
    char *cmdline, *prompt, **arglist;
    int result, process(char **);
    void setup();

    // get user prompt

    prompt = DFL_PROMPT;
    setup();

    while ((cmdline = next_cmd(prompt, stdin)) != NULL) {

        if ((arglist = splitline(cmdline)) != NULL) {
            result = process(arglist);
            freelist(arglist);
        }
        free(cmdline);
    }

    return 0;
}

/*
 * purpose: initialize shell
 * returns: nothing. calls fatal() if trouble
 */

void setup() {
    extern char **environ;
    VLenviron2table(environ);
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}

void fatal(char *s1, char *s2, int n) {
    fprintf(stderr, "Error: %s, %s\n", s1, s2);
    exit(n);
}