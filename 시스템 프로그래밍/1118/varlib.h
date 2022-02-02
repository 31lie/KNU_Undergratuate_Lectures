/* file name: varlib.h
 * author: 2020114658_LEE Yoon Seo
 * datetime: 2021-11-18 18:59
 * description: header file for varlib.c
 */

#define MAXVARS 200

struct var
{
    char *str;
    int global;
};

static struct var tab[MAXVARS];
static char *new_stirng(char *, char *);
static struct var *find_item(char *, int);

int VLstore(char *, char *);
int VLexport(char *);
int VLenviron2table(char *env[]);

char *VLlookup(char *);
char **VLtable2environ();

void VList();