/** @file KinematicsTemplate.h
 * @brief This is a template file to generate  Kinematics structure.
 
 *  A Kinematics function is implemented in this file. The Kinematics function is based around the Kinematics structure, int receives its inputs from the input array and it writes its outputs to the output array. The states and parameters of the Kinematics funciton are also stored
 */

#include "Kinematics.h" ///< Included to obtain the Kinematics struct.


/// Prefix Use a 3 letter prefix for the customizations

/// Kinematics parameters, used to configure the Kinematics
enum KinematicsParameters {
        parameter1,
        parameter2
};

/// Kinematics states, used to store data between iterations of the loop to obtain derivative values.
enum KinematicsStates {
	state1,
	state2,
	
};

/// Inputs to the control function
enum KinematicsInput{
    reference,
    position
    
};

/// Outputs of the control algorithm.
enum KinematicsOutput{
    Kinematics_x,
    Kinematics_y,
    Kinematics_z///< Control output of  control function
    
};



/**
 * Kinematics algorithm
 * @param c pointer to a Kinematics structure
 * @return return values are contained in the Kinematics structures output array
*/
void loopKinematics(Kinematics * c){
    
  
}


///Set Kinematicss parameters. Parameters may be configured with a separate function. Optional function.
void setKinematicsParameters(Kinematics *c ){

}

