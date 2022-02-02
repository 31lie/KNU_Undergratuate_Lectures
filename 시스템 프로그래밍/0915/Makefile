# file: Makefile
# author: 2020114658_LEE Yoon Seo
# datetime: 2021-09-15 22:20
# description: Makefile of each programs

cp1 : cp1.o
	gcc -o $@ $?

who3: who3.o utmplib.o
	gcc -o $@ $?

mywho: mywho.o utmplib.o
	gcc -o $@ $?

cp1.o : cp1.c
	gcc -c $?

who3.o : who3.c
	gcc -c $?

utmplib.o : utmplib.c
	gcc -c $?

mywho.o : mywho.c
	gcc -c $?

clean:
	/bin/rm -f *.o
