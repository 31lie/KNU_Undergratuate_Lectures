# file: Makefile
# author: 2020114658_LEE Yoon Seo
# datetime: 2021-09-23 04:51
# description: Makefile for ls2 and myls

all: ls2, myls


ls2 : ls2.o
	gcc -o $@ $?

myls : myls.o
	gcc -o $@ $?

ls2.o : ls2.c
	gcc -c $?

myls.o : myls.c
	gcc -c $?

clean:
	/bin/rm -rf *.o


