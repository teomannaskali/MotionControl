/** @file SMCController.h
 * @brief Implementation of the Sliding Mode Controller.
 
 *  A sliding mode control function is implemented in this file. The sliding mode function has one algorithm attached to it and it utilizes the inputs and outputs to exchange data. The function can be utilized in two different modes, normal mode and linked mode. If normal mode is used, the inputs to the data structures must be made using the input array. If linked mode is to be used, the input_p array must be filled with pointers to the values that the SMC controller will use.
 *
 */

#include "Controller.h" ///< Included to obtain the Controller struct.


/// Prefix SMC

/// Sliding mode control parameters, used to configure the controller
enum SMC_Parameters {
        SMC_C,  
        SMC_D,
        SMC_Ku,
        SMC_DT
};

/// Sliding mode States, used to store data between iterations of the loop to obtain derivative values.
enum SMC_States {
	SMC_error_old,
	SMC_sigma_old,
	SMC_u_old
};

/// Inputs to the sliding mode function
enum SMC_Input{
    SMC_reference,
    SMC_position
    
};

/// Outputs of the sliding mode control algorithm.
enum SMC_Output{
    SMC_u   ///< Control output of sliding mode control function
    
};



/**
 * Sliding mode control algorithm
 * @param c pointer to a controller structure
 * @return return values are contained in the controller structures output array
*/
void loopSMCController(Controller * c){
    
    double reference;
    double position;
    double error_old = c->state[SMC_error_old];
    double sigma_old = c->state[SMC_sigma_old];
    double u_old = c->state[SMC_u_old];
    
    double dt = c->parameter[SMC_DT];
    
    double u;
    
    // If the inputs are not passed on by pointers, extact position and reference from the pointers
    if (c->linked){
        reference = *(c->input_p[SMC_reference]);
        position = *(c->input_p[SMC_position]);
        
    }
    // If the inputs are directly in the input array use them
    else{
        reference = c->input[SMC_reference];
        position = c->input[SMC_position];
        
    }
    
    // Calculate error and derivative of error
    double error =  reference - position;
    double error_d = (error - error_old)/dt;
    
    // Calculate sigma and derivative of sigma
    double sigma = c->parameter[SMC_C] * error + error_d;
    double sigma_d = (sigma - sigma_old)/dt;
    
    // Calculate control output
    u = u_old + c->parameter[SMC_Ku] * (c->parameter[SMC_D] *sigma + sigma_d);
    
    /// Store states of the controller for the next loop
    c->state[SMC_error_old] = error;
    c->state[SMC_u_old] = u;
    c->state[SMC_sigma_old] = sigma;
    
    // Store the control output u in the output array
    c->output[SMC_u] = u;

}


///Set sliding mode controllers parameters and time constant
void setSMCParameters(Controller *c, double C, double D, double Ku, double dt ){
    c->parameter[SMC_C] = C;
    c->parameter[SMC_D] = D;
    c->parameter[SMC_Ku] = Ku;
    c->parameter[SMC_DT] = dt;
}

