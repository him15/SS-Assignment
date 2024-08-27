// Name : Himanshu Shivhare
// MT2024058
// Program :7. Write a program to copy file1 into file2 ($cp file1 file2).

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>


int main(int argv , char *argc[]){
	int fd1 = open(argc[1] , O_RDONLY);//  file descriptor of file1
	if(fd1 < 0){
		perror("Error in File 1");
		close(fd1);
	}
	int fd2 = open(argc[2] , O_WRONLY | O_CREAT, S_IRWXU);
	if(fd2 < 0){
		perror("Error in File 2");
		close(fd2);
	}

	char buff;
	while(read(fd1 , &buff , 1)){
		write(fd2 , &buff , 1);
	}
	close(fd1);
	close(fd2);
	return 0;

}
