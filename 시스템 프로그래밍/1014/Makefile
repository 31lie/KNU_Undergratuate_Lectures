# file name: Makefile
# author: 2020114658_LEE Yoon Seo
# datetime: 2021-10-14 21:00
# description: makefile for play_again1,2,3,4

all: play_again1 play_again2 play_again3 play_again4

play_again1: play_again1.o
	gcc -o play_again1 play_again1.o

play_again2: play_again2.o
	gcc -o play_again2 play_again2.o

play_again3: play_again3.o
	gcc -o play_again3 play_again3.o

play_again4: play_again4.o
	gcc -o play_again4 play_again4.o

play_again1.o: play_again1.c
	gcc -c play_again1.c

play_again2.o: play_again2.c
	gcc -c play_again2.c

play_again3.o: play_again3.c
	gcc -c play_again3.c

play_again4.o: play_again4.c
	gcc -c play_again4.c

clean:
	/bin/rm -f *.o

