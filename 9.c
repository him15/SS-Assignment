/*
Himanshu Shivhare
MT2024058
9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


int main(int argc, char *argv[]) {
	const char *filename = argv[1];
	struct stat fstat;

	// Print file information
    printf("File: %s\n", filename);
    printf("Inode: %lu\n", (long)fstat.st_ino);
    printf("Number of hard links: %lu\n", (long)fstat.st_nlink);
    printf("UID: %u\n", fstat.st_uid);
    printf("GID: %u\n", fstat.st_gid);
    printf("Size: %ld bytes\n", fstat.st_size);
    printf("Block size: %ld bytes\n", (long)fstat.st_blksize);
    printf("Number of blocks: %ld\n", (long)fstat.st_blocks);

    // Convert and print times
    printf("Time of last access: %s", ctime(&fstat.st_atime));
    printf("Time of last modification: %s", ctime(&fstat.st_mtime));
    printf("Time of last change: %s", ctime(&fstat.st_ctime));

    return 0;
}

/*

File: file1.txt
Inode: 64
Number of hard links: 4
UID: 0
GID: 32768
Size: 0 bytes
Block size: 609885356038 bytes
Number of blocks: 17179869193
Time of last access: Thu Jan  1 05:30:00 1970
Time of last modification: Thu Jan  1 05:30:00 1970
Time of last change: Thu Jan  1 05:30:00 1970

*/
