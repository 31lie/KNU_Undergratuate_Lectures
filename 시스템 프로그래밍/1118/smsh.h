/* file name: smsh.h
 * author: 2020114658_LEE Yoon Seo
 * datetime: 2021-11-18 18:40
 * description: header file for smsh4
 */

#include <sys/types.h>
#include <stdio.h>

#define YES 1
#define NO 0
#define is_delim(x) ((x) == ' ' || (x) == '\t')

char *next_cmd(char *, FILE *);
char **splitline(char *);

void freelist(char **);
void *emalloc(size_t);
void *erealloc(void *, size_t);
void fatal(char *, char *, int);

int execute(char **);
int is_control_command(char *);
int do_control_command(char **);
int ok_to_execute();
int builtin_command(char **, int *);
int syn_err(char *);
int process(char **);
int assign(char *);
int okname(char *);

