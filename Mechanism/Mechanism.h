/** @file Mechanism.h
 * @brief General definition of an mechanism containing the data structures.
 * This file contains the data structure needed to create a mechanism. The data of a mechanism includes its states, its parameters and other modules it utilizes, such as Actuators, Sensors, Axes. The mechanism structure also has access to Kinematics, Controllers, Estimators and Observers.
 */

#ifndef MECHANISM
#define MECHANISM

#include "Actuator.h"
#include "Sensor.h"
#include "Axis.h"

#define MECHAXES 5          ///< Maximum Number of Axes a mechanism may have
#define MECHKINEMATICS 2    ///< Maximum Number of Kinematics functions a Mechanism may have
#define MECHACTUATORS 7     ///< Maximum Number of Actuators a Mechansim may have
#define MECHSENSORS 3       ///< Maximum Number of Sensors a Mechanism may have

#define MECHINPUT 6           ///< Maximum Number of References a Mechanism may have
#define MECHOUTPUT 6

#define MECHSTATES 10       ///< Maximum Number of States a Mechansim may have
#define MECHPARAMETERS 10   ///< Maximum Number of Parameters a Mechanism may have


/// Structure containing the data for an mechanism, including inputs, outputs, state machine state, links to the actuators, sensors, axes, controllers plus, parameters and states for internal storage of data.
struct Mechanism_ {
    
    char * name; ///< name of the actuator
    
    int StateMachine; ///< state machine status of the mechanism
    
    double input[MECHINPUT];
    double output[MECHOUTPUT];
    
    double parameter[MECHPARAMETERS]; ///< Parameters of the Mechanism, used to configure the Mechanism
    double state[MECHSTATES];         ///< States of the Mechanism, used to store internal data of the Mechanism
    
    
    
    Actuator Actuators[MECHACTUATORS];
    Sensor Sensors[MECHSENSORS];
    
    Axis Axes[MECHAXES];
    
//    Kinematic Kinematics[MECHKINEMATICS];
    
   
    
    int (*loopMechanism)(struct Mechanism_ * M);

};

typedef struct Mechanism_ Mechanism;



/*
int loopMechanism(Mechanism * M){
    
    /// get reference for the manipulator
    
    /// Transform the coordinate references to axis references
    
    /// Command axees
    
    return 0;
}
*/
#endif
