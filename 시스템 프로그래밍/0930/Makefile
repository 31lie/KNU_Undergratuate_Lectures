# file name: Makefile
# author: 2020114658_LEE Yoon Seo
# datetime: 2021-09-30 20:23
# description: Makefile for spwd, myspwd command


all: spwd.o myspwd.o

spwd: spwd.o
	gcc -o spwd spwd.o

myspwd: myspwd.o
	gcc -o myspwd myspwd.o

spwd.o: spwd.c
	gcc -c spwd.c

myspwd.o: myspwd.c
	gcc -c myspwd.c

clean:
	/bin/rm -f *.o
