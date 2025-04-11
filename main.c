#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdint.h>



int main(int argc, char* argv[]){

	// inputs
	int L = atoi(argv[1]);
	int H = atoi(argv[2]); // H number of hidden keys that you should look for
			       // H is between 40 and 80
	int pn = atoi(argv[3]);
	int r; // random variable



	// generate the text file with L >= 20,000 integers and 80 negative integers ranging  
	FILE *fd;
	char buffer[16] = {0};
	
	fd = fopen("p1.txt", "w+");
	srand(time(NULL));   

	if(L < 20000){
		L = 20000
	}

	for(int i = 0; i< L; i++){
		r = rand();  

		printf("%d \n", r);

		sprintf(buffer, "%d", r);
		fputs(buffer, fd);
	}



	// find max, average, and number of H


	return 0;
}
