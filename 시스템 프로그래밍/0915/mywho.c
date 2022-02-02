/*
	file: mywho.c
	author: 2020114658_LEE Yoon Seo
	datetime: 2021-09-15 23:29
	description: Edit the form of date print
*/


#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <time.h>


#define SHOWHOST

void show_info(struct utmp*);
void showtime(long);

int utmp_open(char *filename);
struct utmp *utmp_next();
void utmp_close();

int main() {
	struct utmp current_record;
	struct utmp *utbufp, *utmp_next();
	int utmpfd;
	int reclen = sizeof(current_record);

	if (utmp_open(UTMP_FILE) == -1) {
		perror(UTMP_FILE);
		exit(1);
	}

	while ((utbufp = utmp_next()) != ((struct utmp*) NULL))
		show_info(utbufp);
	utmp_close();
	
	return 0;
}

void show_info(struct utmp* utbufp) {

	if (utbufp -> ut_type != USER_PROCESS)
		return;

	printf("%-8.8s", utbufp -> ut_name);
	printf(" ");
	printf("%-8.8s", utbufp -> ut_line);
	printf(" ");
	showtime(utbufp -> ut_time);

#ifdef SHOWHOST
	printf("(%s)", utbufp -> ut_host);
#endif
	printf("\n");
}

void showtime(long timeval) {

	// declare tm struct
	struct tm* time;

	// use localtime funtion for transforming tm struct
	time = localtime(&timeval);

	// Use tm sturct to print it out as I want.
	printf("%d-%02d-%02d %02d:%02d", time->tm_year+1900, time->tm_mon+1, time->tm_mday,time->tm_hour, time->tm_min);
}
