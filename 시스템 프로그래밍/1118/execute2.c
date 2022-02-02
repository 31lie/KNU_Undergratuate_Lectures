/* file name: execute2.c
 * author: 2020114658_LEE Yoon Seo
 * datetime: 2021-11-18 18:38
 * description: code used by small shell to execute commands
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include "smsh.h"
#include "varlib.h"

/*
 * purpose: run a program passing it arguments
 * returns: status returned via wait, or -1 on error
 * errors: -1 on fork() or wait() errors
 */
int execute(char *argv[]) {
    extern char **environ;
    int pid;
    int child_info = -1;

    if (argv[0] == NULL) { // nothing succeeds
        return 0;
    }

    if ((pid = fork()) == -1) {
        perror("fork");
    }

    else if (pid == 0) { // child process
        environ = VLtable2environ();
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        execvp(argv[0], argv);
        perror("cannot execute command");
        exit(1);
    }

    else { // parent process
        if (wait(&child_info) == -1) {
            perror("wait");
        }
    }

    return child_info;
}