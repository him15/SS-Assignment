// Name : Himanshu Shivhare
// MT2024058
// Program : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

#include <unistd.h>
#include <stdio.h>

int main(){
	char buff[200];
	int n = read(0 , buff , 200); // 0 is used to take from command line
	
	if(n < 0){
		perror("Error Reading from STDIN\n");
		return 1;
	}else{
		write(1 , buff , n);
	}
	return 0;
}
