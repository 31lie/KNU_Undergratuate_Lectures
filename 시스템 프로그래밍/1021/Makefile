# file name: Makefile
# author: 2020114658_LEE Yoon Seo
# datetime: 2021-10-21 20:57
# description: makefile for myhello, ticker_demo 

all: myhello ticker_demo

myhello: myhello.c set_ticker.c
	gcc myhello.c set_ticker.c -lcurses -o myhello

ticker_demo: ticker_demo.c set_ticker.c
	gcc ticker_demo.c set_ticker.c -o ticker_demo

