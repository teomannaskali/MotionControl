/*
 *  Sensor.c
 *  
 *
 *  Created by Teoman Naskali on 11/17/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#include "Sensor.h"
#include <stdio.h>


//Write all data here as comment for the encoder

// Encoder to position coefficient 400/(2048*28.44444) 

double readFaulhaberEncoder(Sensor * s){
    printf("Encoder Read:");
    scanf("%lf", &(s->state.value[0]));
    return s->state.value[0];
}

int setFaulhaberEncoder(Sensor* s, double v){
    return 0;
}

int resetFaulhaberEncoder(Sensor* s){
    return 0;
}

int removeFaulhaberEncoder(Sensor*s){
    
    return 0;
}