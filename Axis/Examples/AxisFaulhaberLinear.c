
#include "Axis.h"


    

int removeAxis( Axis * a){return 0;}

int resetAxis(Axis * a){return 0;}


int initAxis(Axis * A){
    return 0;
    
    
}

int stepAxis(Axis* A, double ref){
    
    // CHECK LIMITS
    double output;
    double position;
    //int positiveLimit = A->Sensors[1].read(&A->Sensors[1]);
    
    //int negativeLimit = A->Sensors[2].read(&A->Sensors[2]);
    
    //GET INPUT
    position = A->Sensors[0].read(&A->Sensors[0]);
    
    
    //PERFORM CONTROL
    
    A->Controllers[0].loop(&A->Controllers[0],&position, &ref, &output);
    
    //GENERATE OUTPUT
    A->Actuators[0].write(&A->Actuators[0], output);
    return 0;
}