//Christian D. Kempis, ckempis, CMPS101, pa01
//15 April 2015: Change, added standard input for user

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "intList.h"

#define maxSIZE 1024

typedef struct {
	int from;
	int to;
	double weight;
} Edge;

void parseEdges(char *line, IntList *aVert, int maxSizeOfArray) {
		Edge newE;
		int numFields;
		numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
		if (numFields < 2 || numFields >= 3 || newE.from > maxSizeOfArray) {
			printf("bad edge: %s", line);
			exit(1);
		}

		if (numFields == 2) {
			newE.weight = 0.0;
         	}
		aVert[newE.from] = intCons(newE.to, aVert[newE.from]);
}

int main(int argc, char* argv[]) {
	FILE *input;
    char line[maxSIZE];
    bool userInput = false;
	int verticies;
	int mCount=0;
	IntList *pivot;
	//Check if an input file has been entered
	if (argc != 2) {
		fprintf(stderr, "Missing input data \n");
		exit(0);
	}
	if((strcmp(argv[1],"-")) == 0) {
		printf("Reading from Standard Input\n");
        	userInput = true;
	}
	//Using a File to populate the matrix
	if(userInput == false) {
		//Open File
		char *myFile = argv[1];
		input = fopen(myFile, "r");
        //Check if file exists
        if (input == NULL) {
			fprintf(stderr, "File Open:  Failure\n");
			return(0);
        } else {
		printf("File Open:  Success\n");
		}

        //Get number of vertices (indexes) to create
		fgets(line, sizeof(line), input); //Read in first line 
		sscanf(line, "%d %*s",  &verticies); //Parse number of vertices from first line

        //Initialize the Adjaceny list with number of vertices
		pivot = (IntList*)calloc(verticies+1,sizeof(IntList));
		int start = 1;
			for(start = 1; start <= verticies; start++) {
			pivot[start] = NULL;
		}
		//Read each line until the end of file and save into the matrix
		while (fgets(line, sizeof(line), input)) {
			mCount++;
			parseEdges(line, pivot, verticies);
		}
	// Using Standard Input to population the Matrix
	} else {
		input = stdin;
		printf("Please Enter the size of your array on the next line\n");
		fgets(line, sizeof(line), input); //Read in first line 
		sscanf(line, "%d %*s",  &verticies); //Parse number of vertices from first line
		
		printf("Now enter the indecies by Index and  Numbe (I.E.: 5 6\n");
		//Initialize the Adjaceny list with number of vertices
		pivot = (IntList*)calloc(verticies+1,sizeof(IntList));
		int userStart = 1;
			for(userStart = 1; userStart <= verticies; userStart++) {
			pivot[userStart] = NULL;
		}
		
		//Read each line until the end of file and save into the matrix
		while (fgets(line, sizeof(line), input)) {
			mCount++;
			parseEdges(line, pivot, verticies);
		}
		
	}

        // Output finished matrix
	int count;
    printf("n = %d\nm = %d\n", verticies, mCount); 
	for(count = 1; count <= verticies; count++) {
		IntList printer = pivot[count];
		bool listStart = true;
		printf("%d  ", count);
                if(!printer) {
			printf("Nil\n");
		}
		while(printer) {
			if(listStart == true) {
				printf("[");
			} else {
				printf(", ");
			}
			printf("%d", intFirst(printer));
			printer = intRest(printer);
			listStart = false;
		}
		if(listStart == false) {
			printf("]\n");
		}
	}
        fclose(input);	
	return 0;
}
