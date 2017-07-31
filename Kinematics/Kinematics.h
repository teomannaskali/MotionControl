/** @file Kinematics.h
 * @brief General definition of forward or reverse kinematics, containing the data structures. 
 
 *  A Kinematics structure contains the states and parameters of funtions needed to perform Kinematics operations. The Kinematics structure also has a function pointer to attach an algorithm loop function that is executed in every loop.
 *
 */

#ifndef KINEMATICS
#define KINEMATICS

#define KINEMATICSMAXPARAMETERS 10
#define KINEMATICSMAXSTATES 10

#define KINEMATICSMAXIN 10
#define KINEMATICSMAXOUT 10

/// Kinematics Structure contains the necessary data to run Kinematics. It is composed of four main parts. Input and Output arrays are utilized to exchange data to and from the Kinematics structure during runtime. States of  Kinematics contain the internal varying data and parameters of  Kinematics contain the values that are used to configure the Kinematics structure. 
struct Kinematcis_ {
	
    int linked;                     ///< parameter to define if kinematics works under linked mode or normal mode, in normal mode, the control algorithm receives its inputs directly from its input array whereas in linked mode, the input array's pointers are directed to other parameters in a system and the Kinematics can gather its data from outside.
    
    double input[KINEMATICSMAXIN];    ///< List of inputs to the Kinematics function
    
    double * input_p[KINEMATICSMAXIN]; ///< List of inputs in pointer format to directly add references
    
    double output[KINEMATICSMAXOUT];  ///< List of outputs of the Kinematics function
    
    double state[KINEMATICSMAXSTATES];           ///< States of the Kinematics funtion, internal data that the kinematics function may need.
    double parameter[KINEMATICSMAXPARAMETERS];   ///< Parameters of the Kinematics, may include coefficients or offsets.
    
    
    
    /**
     * this is the function pointer to the algorithm of the Kinematics
     * @param c is a pointer to the Kinematics structure that contains the inputs, outputs, states and parameters of the Kinematics function
     * @return Function does not have a return value, the Kinematics outputs are stored int the output array.
*/
    void (*loopFWKinematics)(struct Kinematics_ * k); ///< This function is the algorithm of the forward Kinematics, it is set by hihger level structures to run once per loop. Every different algorithm using the Kinematics structure must provide a loop function.

};

typedef struct Kinematics_ Kinematics;

#endif