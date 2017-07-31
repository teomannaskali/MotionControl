/*
 *  Sensor.c
 *  
 *
 *  Created by Teoman Naskali on 11/17/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#include "Sensor.h"


double readConveyorStation(Sensor * s){

    return 0;
}

int setConveyorStationParameter(Sensor* s,int parameter, double v){
    s->parameter[parameter]=v;
    
    
    return 0;
}

int resetConveyorStationSensor(Sensor* s){
    // Nothing to do to reset
    return 0;
}

int removeConveyorStationSensor(Sensor*s){
    // Does not need removal of resources
    
    return 0;
}


// The conveyor station sensor does not need additional parameters