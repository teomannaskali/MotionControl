/** \file ActuatorTemplate.c
 * Template file to be copied and filled to add a different type actuator
 * Implementation of the functions of a type of actuator
 * The keywordActuator here must be replaced with an apropriate name for the type of actuator
 */



#include "Actuator.h" ///Addition of the actuator header file
#include "HWWrapper.h" ///Add access to the IO cards of the system

/// To Enable the functions of an actuator these parts should be filled


/** Initializes the actuator.
 @param d pointer to an actuator structure as defined in Actuator.h
*/
int initActuator(Actuator * d){
/// Write initialization code for the actuator
    
    
    return 0;

}


/** Makes the Actuator write its output to its output medium.
 * This funciton outputs to the IO cards, the wrapper template must be included in the project beforehand
 @param d pointer to an actuator structure as defined in Actuator.h
 @param value value to be output to the io card
 */
int writeActuator(Actuator * d, double value){
///Scale the input value and output it to the IO card 
    /// Perform necessary conversions
    setAnalogOutput(d->outDAC[0], value);
    return 0;
}


/** Removes resources allocated to the acutator if they exist.
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int removeActuator(Actuator * d){
///Remove resources here
    return 0;
}


/** Reset the actuator
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int resetActuator(Actuator * d){
///Reset the actuator, utilized in case of an error.
/// Offsets may be initialized here
    return 0;
}


/** Sets the offset for the actuator.
 @param d pointer to an actuator structure as defined in Actuator.h
 */
int setActuatorParameter(Actuator * d,int parameter, double value){
/// 
    d->PARAMETERS[parameter] = value;
    return 0;
}

