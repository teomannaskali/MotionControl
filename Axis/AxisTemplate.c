
#include "Axis.h"




int removeAxis(struct Axis_* a){}

int resetAxis(struct Axis_* a){}


int initAxis(Axis* A){
    
    
    
}

int stepAxis(Axis* A, double ref){
    
    // CHECK LIMITS
    double output;
    
    //int positiveLimit = A->Sensors[1].read(&A->Sensors[1]);
    
    //int negativeLimit = A->Sensors[2].read(&A->Sensors[2]);
    
    //GET INPUT
    double position = A->Sensors[0].read(&A->Sensors[0]);
    
    
    //PERFORM CONTROL
    
    A->Controllers[0].loop(&A->Controllers[0], &ref,&position, &output);
    
    //GENERATE OUTPUT AND OUTPUT
    A->Actuators[0].write(&A->Actuators[0], output);
}