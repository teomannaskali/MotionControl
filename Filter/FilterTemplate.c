/*
 *  Filter.c
 *  
 *
 *  Created by Teoman Naskali on 1/8/12.
 *  Copyright 2012 Sabanci University. All rights reserved.
 *
 */

#define PARAMCOUNT 20
#define ORDER 5

struct Filter {
	string name;
	double P[PARAMCOUNT];

}

void initFilter( struct Filter * F, double P1, double P2, double P3 ){
	// Initialize filter parameters
}

void FilterAlg(double in[], double out[], struct Filter F){
	// perform the filtreation here, update the input and outupt parameters as necessary

}

void deleteFilter(struct Filter *F){
	// Release resources
}