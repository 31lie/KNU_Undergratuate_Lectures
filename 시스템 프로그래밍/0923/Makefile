# file name: Makefile
# author: 2020114658_LEE Yoon Seo
# datetime: 2021-10-07 23:34
# description: makefile for write0.c, mywrite0.c

all: write0 mywrite

write0: write0.o
	gcc -o $@ $?

mywrite: mywrite.o
	gcc -o $@ $?

write0.o: write0.c
	gcc -c $?

mywrite.o: mywrite.c
	gcc -c $?

