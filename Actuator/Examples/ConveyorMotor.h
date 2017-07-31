/** \file ConveyorMotor.h
 * Conveyor motor file describing the conveyor motor as an actuator
 */



#include "Actuator.h" ///Addition of the actuator header file
#include "HWWrapper.h" ///Add access to the IO cards of the system

/// To Enable the functions of an actuator these parts should be filled

enum ConveyorMotorParameters {
    
    Speed = 0,
    MetersPerVolt = 1
};


/** Initializes the actuator.
 @param d pointer to an actuator structure as defined in Actuator.h
*/
int initConveyorMotor(Actuator * d){
/// Write initialization code for the actuator
    return initAnalogOutput(d->outDAC[0]);
    

}


/** Set the speed for the conveyor
 @param d pointer to an actuator structure as defined in Actuator.h
 @param speed speed for the conveyor
 */
int writeConveyorMotor(Actuator * d, double speed){

    
    double volts = speed/d->PARAMETERS[ConveyorMotorParameters.MetersPerVolt];///Convert speed to volts
    
    setAnalogOutput(d->outDAC[0], volts);
    
    return 0;
}


/** Removes resources allocated to the acutator if they exist.
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int removeConveyorMotor(Actuator * d){
///IO card does not need remvoal
    
    return 0;
}


/** Reset the actuator
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int resetConveyorMotor(Actuator * d){
    // output 0 volts to stop the conveyor
    setAnalogOutput(d->outDAC[0], 0);
    return 0;
}


/** Sets the parameter for the actuator.
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int setConveyorMotorParameter(Actuator * d,int parameter, double value){
/// 
    d->PARAMETERS[parameter] = value;
    return 0;
}

