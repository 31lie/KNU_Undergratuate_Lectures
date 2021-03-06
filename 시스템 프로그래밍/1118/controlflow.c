/* file name: controlflow.c
 * author: 2020114658_LEE Yoon Seo
 * datetime: 2021-11-18 18:31
 * description: "if" processing is done with two state variables if_state and if_result
 */

#include <string.h>
#include <stdio.h>
#include "smsh.h"

enum states {NEUTRAL, WANT_THEN, THEN_BLOCK};
enum results {SUCCESS, FAIL};

static int if_state = NEUTRAL;
static int if_result = SUCCESS;
static int last_stat = 0;

/*
 * purpose: determine the shell should execute a command
 * returns: 1 for yes, 0 for no
 * details: if in THEN_BLOCK and if_result was SUCESS then yes
 *          if in THEN_BLOCK and if_result was FAIL then no
 *          if in WANT_THEN then syntax error (sh is different)
 */
int ok_to_execute() { 

    int rv = 1; // default is positive

    if (if_state == WANT_THEN) {
        syn_err("then expected");
        rv = 0;
    }

    else if (if_state == THEN_BLOCK && if_result == SUCCESS) {
        rv = 1;
    }

    else if (if_state == THEN_BLOCK && if_result == FAIL) {
        rv = 0;
    }

    return rv;
}

/*
 * purpose: boolean to report if the command is a shell control command
 * returns: 0 or 1
 */
int is_control_command(char *s) {
    return (strcmp(s, "if") == 0 || strcmp(s, "then") == 0 || strcmp(s, "fi") == 0);
}

/*
 * purpose: process "if", "then", "fi" - change state or detect error
 * returns: 0 if ok, -1 for syntax errpr
 */
int do_control_command(char **args) {

    char *cmd = args[0];
    int rv = -1;
    if (strcmp(cmd, "if") == 0) {
        if (if_state != NEUTRAL) {
            rv = syn_err("if unexpected");
        }
        else {
            last_stat = process(args + 1);
            if_result = (last_stat == 0 ? SUCCESS : FAIL);
            if_state = WANT_THEN;
            rv = 0;
        }
    }

    else if (strcmp(cmd, "then") == 0) {
        if (if_state != WANT_THEN) {
            rv = syn_err("then unexpected");
        }
        else {
            if_state = THEN_BLOCK;
            rv = 0;
        }
    }

    else if (strcmp(cmd, "fi") == 0) {

        if (if_state != THEN_BLOCK) {
            rv = syn_err("fi unexpected");
        }

        else {
            if_state = NEUTRAL;
            rv = 0;
        }
    }

    else {
        fatal("internal error processing:", cmd, 2);
    }

    return rv;
}

/*
 * purpose: handles syntax errors in control structures
 * returns: resets state to NETURAL
 * returns: -1 in interactive mode. should call fatal in scripts
 */

int syn_err(char *msg) {
    
    if_state = NEUTRAL;
    fprintf(stderr, "syntax erorr: %s\n", msg);
    return -1;
}