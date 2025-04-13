#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int chain() {  

	pid_t pid; 


	printf("Parent process (PID: %d)\n", getpid());  

	int count; 
	for (int i = 0; i < 1000000000; ++i) {  

		pid = fork();
		
		if(pid < 0){
			printf("final count: %d \n", count);	
			perror("fork failed!");
			exit(-1);

		}

		if ( pid == 0) {  
			printf("Child process (PID: %d) with parent (PPID: %d)\n", getpid(), getppid());  
			++count;
			break;   
		}  
	}  
	return 0;  
}


int fan() {  
	printf("Parent process (PID: %d)\n", getpid());  
	for (int i = 0; i < 10000; ++i) {  
		if (fork() == 0) {  
			printf("Child process (PID: %d) with parent (PPID: %d)\n", getpid(), getppid());  
			return 0;   
		}  
	}  
	return 0;  
}


int main(){

	chain();
	return 0;	
}
