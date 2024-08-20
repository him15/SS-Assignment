#include<stdio.h>
#include<unistd.h>

int main(){
	const char*dest = "hello1.txt";
	const char*src = "hello1_src.txt";

	if(symlink(dest, src) != 0){
		perror("symlink");
		return 1;
	
	}

printf("The Link is been Created");
}
