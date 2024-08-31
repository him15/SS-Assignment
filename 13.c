/*
Himanshu Shivhare
MT2024058

13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/




#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
    struct timeval timeout;
    fd_set readfds;
    
    // Initialize the file descriptor set to monitor stdin (file descriptor 0)
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    
    // Set the timeout value
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    
    // Call select to monitor file descriptors
    int result = select(1, &readfds, NULL, NULL, &timeout);
    
    // Check the result of select
    if (result == -1)
    {
        perror("select failed"); // Use perror for more descriptive error reporting
    }
    else if (result == 0)
    {
        printf("Timeout occurred\n");
    }
    else
    {
        printf("Input available\n");
    }

    return 0;
}

/*
Output 
	 Timeout Occured
*/
