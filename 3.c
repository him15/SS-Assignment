//  Name - Himanshu Shivhare
//  MT2024058
// 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int val = creat("file3.txt" , S_IRUSR | S_IWUSR);
	if(val == -1){
		perror("CREAT ERROR\n");
		return 1;
	}
	printf("Created Succesfully  %d\n", val);
	return 0;

}
