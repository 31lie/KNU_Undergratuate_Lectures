/* 
    file name: mywrite.c
    author: 2020114658_LEE Yoon Seo
    datetime: 2021-10-07 23:28
    description: edit write0.c code, and it prints welcome comment at first to anoter user
 */

#include <stdio.h>
#include <fcntl.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int ac, char *av[]) {

    struct passwd *pd;
    struct tm *t;

    char *end_of_stream = "EOF\n";
    char buf[BUFSIZ];
    char comment_buf[BUFSIZ];

    time_t time_value;
    int fd;

    // get a user ID and current time for inserting to comment
    time_value = time(NULL);
    t = localtime(&time_value);
    pd = getpwuid(geteuid());

    // put a comment to comment_buf
    sprintf(comment_buf, "\nMessage from %s at %02d:%02d ...\n", pd->pw_name, t->tm_hour, t->tm_min);

    if (ac != 2) {
        fprintf(stderr, "usage: write0 ttyname\n");
        exit(1);
    }

 
    fd = open(av[1], O_WRONLY);

    if (fd == -1) {
        perror(av[1]);
        exit(1);
    }


    // print first comment to another user
    write(fd, comment_buf, strlen(comment_buf));

    while (fgets(buf, BUFSIZ, stdin) != NULL) {
        if (write(fd, buf, strlen(buf)) == -1) {
            break;
        }
    }

    // print EOF comment to another user finally
    write(fd, end_of_stream, strlen(end_of_stream));

    close(fd);

    return 0;
}
