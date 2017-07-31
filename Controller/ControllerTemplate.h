/** @file ControllerTemplate.h
 * @brief This is a template file to generate a controller.
 
 *  A controller is implemented in this file. The Controller is based around the Controller structure, int receives its inputs from the input array and it writes its outputs to the output array. The states of the controller c*
 */

#include "Controller.h" ///< Included to obtain the Controller struct.


/// Prefix Use a 3 letter prefix for the customizations

/// Controller parameters, used to configure the controller
enum ControllerParameters {
        parameter1,
        parameter2
};

/// Controller states, used to store data between iterations of the loop to obtain derivative values.
enum ControllerStates {
	SMC_error_old,
	SMC_sigma_old,
	SMC_u_old
};

/// Inputs to the control function
enum ControllerInput{
    reference,
    position
    
};

/// Outputs of the control algorithm.
enum ControllerOutput{
    u   ///< Control output of  control function
    
};



/**
 * Control algorithm
 * @param c pointer to a controller structure
 * @return return values are contained in the Controller structures output array
*/
void loopController(Controller * c){
    
  
}


///Set controllers parameters and time constant. Parameters may be configured with a separate function
void setControllerParameters(Controller *c ){

}

