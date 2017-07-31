//
//  SystemTemplate.c
//  
//
//  Created by Teoman Naskali on 2/8/12.
//  Copyright 2012 Sabanci University. All rights reserved.
//

#include <stdio.h>

#include "../Actuators/Examples/FaulhaberMotor.c"

#include  "../Sensors/Examples/FaulhaberEncoder.c"

#include "../Axes/Examples/AxisFaulhaberLinear.c"

#include "../Controllers/Examples/CengizController.h"


Actuator FM[9];

Sensor   FS[9];

Axis A[9];


Controller C1 , C2;


int initSystem(){

    // SETUP ACTUATOR
	setupActuator(&FM[0], "Motor0","N/m",3,0,1, initFaulhaber, writeFaulhaber,deleteFaulhaber,resetFaulhaber,setFaulhaberOffset);
    
    
    
    //SETUP SENSOR
    setupSensor(&FS[0],
                "FaulhaberEncoder0", 
                "um", 
                0, 
                0, 
                0, 
                3,
                readFaulhaberEncoder,
                setFaulhaberEncoder,
                resetFaulhaberEncoder,
                removeFaulhaberEncoder
                );
    
   
    
    //Setup Controller
    initProportionalController(&C1,3);
   
    
    //SETUP AXIS
    setupAxis(&(A[0]),"Left1", initAxis, stepAxis,removeAxis,resetAxis);
    
    A[0].Sensors[0] = FS[0];
    A[0].Actuators[0] = FM[0];
    A[0].Controllers[0] = C1;
    
    A[0].Controllers[0].loop = loopProportional;
    

    
    return 0;
}

int deleteSystem(){
    return 0;
}

enum states {Homing, Disabled, Active};

int loopSystem(){
    
    A[0].step(&A[0], 9);
    
    
    return 0;
}


