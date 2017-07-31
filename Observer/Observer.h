/*
 *  Observer.h
 *  
 *
 *  Created by Teoman Naskali on 1/8/12.
 *  Copyright 2012 Sabanci University. All rights reserved.
 *
 */

/**
 * @file Observer.h
 * @author Teoman Naskali
 * @date 1/8/2012
 * @brief File containing the observer paramter structure.
 *
 * This file contains the parameter sturcture containing the parameters for various observers.
 */


#ifndef OBSERVER
#define OBSERVER

#define OBSERVERPARAMCOUNT 5 /// Number of parameters for the observer.
#define STATECOUNT 5 /// Number of states of the oberver.


/**
 * @brief Structure containing parameters and states of an observer.
 *
 * Structure containing parameters and states of an observer.
 */
typedef struct Observer_ {
	char* name; /// Name of observer
	double P[OBSERVERPARAMCOUNT]; /// Parameters of the observer
    double S[STATECOUNT]; // States of the observer

};

typedef struct Observer_ Observer;



#endif
