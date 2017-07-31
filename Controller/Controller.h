/** @file Controller.h
 * @brief General definition of a controller containing the data structures. 
 
 *  A controller structure contains the states and parameters a controller. The controller structure also has a function pointer to attach an algorithm loop function that is executed in every loop.
 *
 */

#ifndef CONTROLLER
#define CONTROLLER

#define CONTROLLERMAXPARAMETERS 10
#define CONTROLLERMAXSTATES 10

#define CONTROLLERMAXIN 10
#define CONTROLLERMAXOUT 10

/// Controller Structure contains the necessary data to run a controller. It is composed of four main parts. Input and Output arrays are utilized to exchange data to and from the controller structure during runtime. States of a controller contain the internal varying data and parameters of the controller contain the values are used to tune the controller. 
struct Controller_ {
	
    int linked;                     ///< parameter to define if a controller works under linked mode or normal mode, in normal mode, the control algorithm receives its inputs directly from its input array whereas in linked mode, the input array's pointers are directed to other parameters in a system and the controller can gather its data from outside.
    
    double input[CONTROLLERMAXIN];    ///< List of inputs to the controller
    
    double * input_p[CONTROLLERMAXIN]; ///< List of inputs in pointer format to directly add references
    
    double output[CONTROLLERMAXOUT];  ///< List of outputs of the controller
    
    double state[CONTROLLERMAXSTATES];           ///< States of the controller, internal data that the actuator may need.
    double parameter[CONTROLLERMAXPARAMETERS];   ///< Parameters of the controller, may include coefficients or offsets.
    
    
    
    /**
     * this is the function pointer to the algorithm of the controller
     * @param c is a pointer to the Controller structure that contains the inputs, outputs, states and parameters of the controller
     * @return Function does not have a return value, the controller outputs are stored int the output array.
*/
    void (*loopController)(struct Controller_ * c); ///< This function is the algorithm of the controller, it is set by hihger level structures to run once per loop. Every different algorithm using the Controller structure must provide a loop function.
};

typedef struct Controller_ Controller;

#endif