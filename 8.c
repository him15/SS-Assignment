/*
Name : Himanshu Shivhare
MT2024058

8. Write a program to open a file in read only mode, read line by line and
display each line as it is read. Close the file when end of file is reached.
*/
#include <stdio.h>

int main(){
	FILE *file;
	char buff[1000];
	const char *fname = "file1.txt";  // file name
	
	// fopen function read the file in read only mode.
	file = fopen(fname , "r"); // open the file in read-only mode
	if(file == NULL){
		perror("Error occurred!");
		return 1;
	}

	// read the content and display the content line by line in the buff
	// return NULL when it read the end of the file.
	while(fgets(buff , sizeof(buff) , file) != NULL){
		printf("%s" , buff);
	}
	
	fclose(file);
	return 0;
}
