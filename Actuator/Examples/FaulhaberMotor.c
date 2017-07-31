/*
 *  Actuator.c
 *  
 *
 *  Created by Teoman Naskali on 11/17/11.
 *  Copyright 2011 Sabanci Univrsity. All rights reserved.
 *
 */

// MODIFIED VERSION OF THE ACTUATOR TEMPLATE TO SUIT THE FAULHABER MOTOR
#include "Actuator.h"
#include <stdio.h>

int initFaulhaber( Actuator *d){
    return 0;
}

int deleteFaulhaber(Actuator* d){
    return 0;
}

int writeFaulhaber( Actuator *d, double value){
	//return setAnalogOutput(d->outputIO, d->conversion*value - d->offset);
    printf("yazildi %s %lf\n",d->name,value);
    return 0;
}

int resetFaulhaber(Actuator * d){
    return 0;
}

int setFaulhaberOffset(Actuator * d, double offset){
    return 0;
}


