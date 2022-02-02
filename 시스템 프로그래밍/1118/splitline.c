/* file name: splitline.c
 * author: 2020114658_LEE Yoon Seo
 * datetime: 2021-11-18 18:49
 * description: command reading and parsing functions for smsh
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smsh.h"

/* 
 * purpose: read next command line from fp
 * returns: dynamically allocated string holding command line
 * errors: NULL at EOF (not really an error)
 *         calls fatal from emalloc()
 * notes: allocates space in BUFSIZE chunks
 */

char *next_cmd(char *prompt, FILE *fp) {

    char *buf;        // the buffer
    int bufspace = 0; // total size
    int pos = 0;      // current position
    int c;            // input char

    printf("%s", prompt); // prompt user

    while ((c = getc(fp)) != EOF) {

        if (pos + 1 >= bufspace) { // 1 for \0

            if (bufspace == 0) { // y: 1st time
                buf = emalloc(BUFSIZ);
            }
            else { // or expand
                buf = erealloc(buf, bufspace + BUFSIZ);
            }
            bufspace += BUFSIZ; // update size
        }

        // end of command?
        if (c == '\n') {
            break;
        }

        // no, add to buffer
        buf[pos++] = c;
    }

    if (c == EOF && pos == 0) {             // EOF and no input
        return NULL; // say so
    }

    buf[pos] = '\0';

    return buf;
}

/* 
 * purpose: split a line into array of white-space separated tokens
 * returns: a NULL-terminated array of pointers to copies of the tokens or NULL if line if no tokens on the line
 * action: traverse the array, locate strings, make copies
 * notes: strtok() could work, but we may want to add quotes later
 */

char **splitline(char *line) {

    char *newstr();
    char **args;
    int spots = 0;    // spots in table
    int bufspace = 0; // bytes in table
    int argnum = 0;   // slots used
    char *cp = line;  // pos in string
    char *start;
    int len;

    if (line == NULL) { // handle special case
        return NULL;
    }

    args = emalloc(BUFSIZ); // initialize array
    bufspace = BUFSIZ;
    spots = BUFSIZ / sizeof(char *);

    while (*cp != '\0') {

        while (is_delim(*cp)) { // skip leading spaces
            cp++;
        }

        if (*cp == '\0') { // quit at end-o-string
            break;
        }

        // make sure the array has room (+1 for NULL)
        if (argnum + 1 >= spots) {
            args = erealloc(args, bufspace + BUFSIZ);
            bufspace += BUFSIZ;
            spots += (BUFSIZ / sizeof(char *));
        }

        // mark start, then find end of word
        start = cp;
        len = 1;

        while (*++cp != '\0' && !(is_delim(*cp))) {
            len++;
        }

        args[argnum++] = newstr(start, len);
    }

    args[argnum] = NULL;
    return args;
}

/*
 * purpose: constructor for strings
 * returns: a string, never NULL
 */
char *newstr(char *s, int l)
{
    char *rv = emalloc(l + 1);
    rv[l] = '\0';
    strncpy(rv, s, l);
    return rv;
}

/*
 * purpose: free the list returned by splitline
 * returns: nothing
 * action: free all strings int list and then free the list
 */
void freelist(char **list)
{
    char **cp = list;
    while (*cp)
    {
        free(*cp++);
    }
    free(list);
}

void *emalloc(size_t n)
{
    void *rv;
    if ((rv = malloc(n)) == NULL)
    {
        fatal("out of memory", "", 1);
    }
    return rv;
}

void *erealloc(void *p, size_t n)
{
    void *rv;
    if ((rv = realloc(p, n)) == NULL)
    {
        fatal("realloc() failed", "", 1);
    }
    return rv;
}