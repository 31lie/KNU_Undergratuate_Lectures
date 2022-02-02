/*
file: myls.c
author: 2020114658_Lee Yoon Seo
datetime: 2021-09-23 04:40
description: solve the bug for ls2 code
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>    // Add Header file for malloc (dynamic allocationg)
#include <pwd.h>
#include <grp.h>



void do_ls(char[]);
void dostat(char*);
void show_file_info(char*, struct stat *);
void mode_to_letters(int, char[]);
char* uid_to_name(uid_t);
char* gid_to_name(gid_t);

int main(int ac, char *av[]) {

	if (ac==1)
		do_ls(".");
	else {
		while (--ac) {
			printf("%s: \n", *++av);
			do_ls(*av);
		}
	}

	return 0;
}


void do_ls(char dirname[]) {

	DIR *dir_ptr;
	struct dirent *direntp;

	// declare char* for the absolute path
	char* path;

	if ((dir_ptr = opendir(dirname)) == NULL)
		fprintf(stderr, "ls1: cannot open %s\n", dirname);
	else {
		while ((direntp = readdir(dir_ptr)) != NULL) {

			// use Dynamic Allocating for string size
			// It prevents Segmentation Fault: maybe it occurs because of memory size, I guess.
			// plus 1 for "/" - be used for expressing path
			char *path = malloc(strlen(dirname) + strlen(direntp -> d_name) +1);
			// copy dirname to path(empty)
			strcpy(path, dirname);

			// concatnate path + "/", it looks like "tmp/" for example
			strcat(path, "/");
			// complete absolute path 
			strcat(path, direntp -> d_name);
			
			// pass it
			dostat(path);
			
			// free memory, it doesn't need to be initialize.
			free(path);
		}
		closedir(dir_ptr);
	}

}


void dostat(char* filename) {

	struct stat info;

	if (stat(filename, &info) == -1)
		perror(filename);
	else
		show_file_info(filename, &info);

}


void show_file_info(char* filename, struct stat *info_p) {

	char *uid_to_name(), *ctime(), *gid_to_name(), *filemode();
	void mode_to_letters();
	char modestr[11];

	mode_to_letters(info_p -> st_mode, modestr);

	printf(" %s ", modestr);
	printf(" %4d ", (int) info_p -> st_nlink);
	printf(" %-8s ", uid_to_name(info_p -> st_uid));
	printf(" %-8s ", gid_to_name(info_p -> st_gid));
	printf(" %8d ", (int32_t) info_p -> st_size);
	printf(" %.12s ", 4 + ctime(&info_p -> st_mtime));
	printf(" %s\n", filename);

}


void mode_to_letters(int mode, char str[]) {

	strcpy(str, "----------");

	if (S_ISDIR(mode)) str[0] = 'd';
	if (S_ISCHR(mode)) str[0] = 'c';
	if (S_ISBLK(mode)) str[0] = 'b';

	if (mode & S_IRUSR) str[1] = 'r';
	if (mode & S_IWUSR) str[2] = 'w';
	if (mode & S_IXUSR) str[3] = 'x';

	if (mode & S_IRGRP) str[4] = 'r';
	if (mode & S_IWGRP) str[5] = 'w';
	if (mode & S_IXGRP) str[6] = 'x';

	if (mode & S_IROTH) str[7] = 'r';
	if (mode & S_IWOTH) str[8] = 'w';
	if (mode & S_IXOTH) str[9] = 'x';
}

char* uid_to_name(uid_t uid) {

	struct passwd *getpwuid(), *pw_ptr;
	static char numstr[10];

	if ((pw_ptr = getpwuid(uid)) == NULL) {

			sprintf(numstr, "%d", uid);
			return numstr;
	}

	else
		return pw_ptr -> pw_name;
}


char* gid_to_name(gid_t gid) {

	struct group *getgrgid(), *grp_ptr;
	static char numstr[10];

	if ((grp_ptr = getgrgid(gid)) == NULL) {
		sprintf(numstr,"%d", gid);
		return numstr;
	}

	else
		return grp_ptr -> gr_name;
}

	
