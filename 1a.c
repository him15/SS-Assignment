/*
	Name : Himanshu Shivhare
	Roll No. : MT2024058
	Program :a. soft link (symlink system call)
*/

#include<stdio.h>
#include<unistd.h>

// ls -l           -> used to show all the files in list format


int main(){
	printf("Hello Program /n");
	const char*dest = "hello1.txt";
	const char*src = "hello2_src.txt";
	int res = symlink(dest , src);
	if(res != 0){
		perror("symlink____________");  // if file is already been created then it will show the error.
		return 1;
	
	}else{
		printf("Soft Link is Created succesfully! ");
	
	}


}

//     ./a.out
//     symlink____________: File exists
