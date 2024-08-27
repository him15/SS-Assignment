// Name - Himanshu Shivhare
// MT2024058
// program 5 :  Write a program to create five new files with infinite loop. Execute the program in the background
// and check the file descriptor table at /proc/pid/fd.

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int filedisc[5]; // This array contain the file descriptor
	char fileName[30];
	
	// create and open the 5 file 
	for(int i = 0; i < 5; i++){
		sprintf(fileName , "file%d.txt" , i );  // used to format and store a string into a buffer.
		filedisc[i] = open(fileName , O_CREAT | O_WRONLY | O_APPEND , 0644);
	 //red text are the  flags to ensure that they are created if they don't exist and are opened for writing.
		if(filedisc[i] < 0){
			perror("Open Error ");
			exit(EXIT_FAILURE);
		}else{
			printf("File %d is created successfully \n" , i);
		}
	
	}
	return 0;
}	
