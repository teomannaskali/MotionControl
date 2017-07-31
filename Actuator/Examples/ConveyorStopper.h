/** \file ConveyorStopper.h
    This file is the implementation of the solenoid actuator to stop trays at the positions of a conveyor.
    Any solenoids may be implemented as actuators using this file
 */



#include "Actuator.h" ///Addition of the actuator header file
#include "HWWrapper.h" ///Add access to the IO cards of the system




/** Initializes the Stopper.
 @param d pointer to an actuator structure as defined in Actuator.h
*/
int initConveyorStopper(Actuator * d){
/// Write initialization code for the actuator
    return initDigitalOutput(d->outDIO[0]);
    
}


/** Makes the Actuator write its output to its output medium.
 * This funciton outputs to the IO cards, the wrapper template must be included in the project beforehand
 @param d pointer to an actuator structure as defined in Actuator.h
 @param value value to be output to the io card
 */
int writeConveyorStopper(Actuator * d, double value){
///Scale the input value and output it to the IO card 
    /// Perform necessary conversions
    int output;
    
    if (value!=0)output =1;
    else output =1;
    
    setDigitalOutput(d->outDIO[0],output);
    return 0;
}


/** Removes resources allocated to the acutator if they exist.
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int removeConveyorStopper(Actuator * d){
///No resources to be remvoed
    return 0;
}


/** Reset the actuator
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int resetConveyorStopper(Actuator * d){
    /// Conveyor stoppers do not have a reset so simply the output is set to low
    setDigitalOutput(d->outDIO[0],0);
    return 0;
}


/** Sets a parameter of the conveyor stopper.
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int setConveyorStopperParameter(Actuator * d,int parameter, double value){
/// The conveyor stopper does not have a value
    d->parameter[parameter] = value;
    return 0;
}

