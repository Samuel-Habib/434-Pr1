#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdint.h>
#include <unistd.h>
#include <math.h>


int main(int argc, char* argv[]){

	// inputs
	int L = atoi(argv[1]);
	int H = atoi(argv[2]); // H number of hidden keys that you should look for
			       // H is between 40 and 80
	int pn = atoi(argv[3]);
	int r; // random variable

	// input error handling
	
	if(L < 20000){
		L = 20000;
	}

	if(H > 80 || H < 40){
		perror("H must be between 40 and 80");
		exit(-1);
	}

	// generate the text file with L >= 20,000 integers and 80 negative integers ranging  
	FILE *fd;
	char buffer[16] = {0};
	char *fname = "p1.txt";	

	if(access(fname, F_OK) != 0){

		fd = fopen(fname, "w+");

		srand(time(NULL));   

		// positions loop
		int pos[H];
		for(int i = 0; i< H; i++){
			pos[i] = rand() % L +1;		
		}

		for(int i = 0; i< L; ++i){
			r = rand();  

			for(int j = 0; j < H; ++j){
				if(i == pos[j]){
					r = -1 * (rand() % 80 + 1);
				}
			}

			//		printf("%d \n", r);

			sprintf(buffer, "%d", r);
			fputs(buffer, fd);
			fputs(" ", fd);
		}


	} else{
		fd = fopen(fname, "r");
	}



	return 0;
}


int *DFS_calc(char* fname, int H, int pn){
	// returns an array [max, avg, # of H]
	// traverses with Depth first search

	int *calc = malloc(3);


	int level;
	for(int i = 0; i< pn; ++i){

		if( (pn - pow(2, i)) > 0 ){
			level = i;
		}
	}


	pid_t pid;
	int arr[3];

	for(int i = 0; i<level; ++i){
		pid = fork();	
	}


	if((pid  = 0)) {
		// child process

	} else{
		// parent process	

	}

	return calc;

}

