/*
 *  Filter.c
 *  
 *
 *  Created by Teoman Naskali on 1/8/12.
 *  Copyright 2012 Sabanci University. All rights reserved.
 *
 */

#ifndef FILTER 
#define FILTER

#define PARAMCOUNT 20
#define ORDER 5

struct Filter_ {
	char* name;
	double P[PARAMCOUNT];

};

typedef struct Filter_ Filter;

void initFilter( Filter * F, double P1, double P2, double P3 ){
	// Initialize filter parameters
}

void FilterAlg(Filter F, double in[], double out[] ){
	// perform the filtreation here, update the input and outupt parameters as necessary

}

void deleteFilter( Filter *F){
	// Release resources
}



#endif 