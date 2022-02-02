/*
    file: read.c
    author: 2020114658_LEE Yoon Seo
    datetime: 2021-12-02 11:36
    description: implementation of read
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


void main(int ac, char **av) {

    // declare two file descriptor
	int fd;
	int newfd;

    // open input file
    fd = open(av[2], O_RDONLY);
    
    // connect fd to stdin
    newfd = dup2(fd, 0);

    // close fd - it doesn't need anymore
    close(fd);
		
    // execute command
	execlp(av[1], av[1], NULL);
}


