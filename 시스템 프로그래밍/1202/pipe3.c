/*
    file: pipe3.c
    author: 2020114658_LEE Yoon Seo
    datetime: 2021-12-02 12:56
    description: add two more fd (pipe)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define oops(m,x) {perror(m); exit(x);}

void main(int ac, char **av) {

	int thepipe1[2],	
	    thepipe2[2], 
	    fd, 
        newfd,		
        pid1, 
        pid2;		

	if(ac != 5) {
		fprintf(stderr, "usage: pipe2 cmd1 cmd2 cmd3 cmd4\n");
		exit(1);
	}

	if(pipe(thepipe1) == -1)	
		oops("Cannot get a pipe", 1);

	if((pid1 = fork()) == -1)	
		oops("Cannot fork", 2);

	if(pid1 > 0) {		

		close(thepipe1[1]);	

		if(dup2(thepipe1[0], 0) == -1)
			oops("could not redirect stdin", 3);

		close(thepipe1[0]);	

        // cread file with file descriptor
		fd = creat(av[4], 0644);
        // connect fd to stdout
		newfd = dup2(fd, 1);

		execlp(av[3], av[3], NULL);
		oops(av[3], 4);
	}

        close(thepipe1[0]);
	
	if(dup2(thepipe1[1], 1) == -1)
		oops("could not redirect stdout", 4);

	close(thepipe1[1]);


	if(pipe(thepipe2) == -1)
		oops("Cannot get a pipe", 1);

	if((pid2 = fork()) == -1)
		oops("Cannot fork", 2);


	if(pid2 > 0) {

		close(thepipe2[1]);

		if(dup2(thepipe2[0], 0) == -1)
			oops("could not redirect stdin", 3);

		close(thepipe2[0]);
		execlp(av[2], av[2], NULL);
		oops(av[2], 4);
	}

	close(thepipe2[0]);

	if(dup2(thepipe2[1], 1) == -1)
		oops("could not redirect stdout", 4);
	close(thepipe2[1]);

	execlp(av[1], av[1], NULL);
	oops(av[1], 5);

}
