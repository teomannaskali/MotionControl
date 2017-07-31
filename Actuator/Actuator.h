/** @file Actuator.h
 * @brief General definition of an actuator containing the data structures. An actuator structure Contains the staes and parameters of an actuator along with the channel numbers for the IO's. The actuator structure also has function pointers to attach initialization, writing, removal, resetting and parameter setting functions.
 * 
 */

#ifndef ACTUATOR 
#define ACTUATOR


#define ACTMAXIO 3 ///< Defines the number of maximum different types input or output IO channel access by a single actuator
#define ACTMAXIN 3     ///< Defines the maximum number of inputs all actuators may have
#define ACTMAXOUT 3    ///< Defines the maximum number of outputs all actuators may have
#define ACTMAXSTATES 5 ///< Define the maximum number of states that all actuator may have
#define ACTMAXPARAMETERS 4 ///< Define the maximum number of parameters that all actuators may have



/// Actuator structure contains all the parameters states IO channels and function pointers to an actuator structure
struct Actuator_ {
    
	char* name;             ///< Name of the actuator
	char* units;            ///< String containing units of actuator to be used for reporting

	double input[ACTMAXIN];    ///< List of inputs to the actuator
    double output[ACTMAXOUT];  ///< List of outputs of the actuator
   
    double state[ACTMAXSTATES];           ///< States of the actuator, internal data that the actuator may need.
    double parameter[ACTMAXPARAMETERS];   ///< Parameters of the actuator, may include coefficients of offsets.
    
	int outDIO[ACTMAXIO];          ///<List of the digital output channels that the actuator may have
    int inDIO[ACTMAXIO];           ///<List of the digital input channels that the actuator may have
    int inADC[ACTMAXIO];           ///<List of the analog input channels that the actuator may have
    int outDAC[ACTMAXIO];          ///<List of the analog output channels that the actuator may have
    int inENC[ACTMAXIO];           ///<List of the encoder channels that the actuator may have
    
    
    
    /// Function pointer to initialize the actuator
    /// Initialize the necessary inputs and outputs to be utilized for this actuators
    /// @brief initialize the actuator
    /// @param d pointer to the actuator structure
    /// @return 0 for success, -1 for error
    int (*init)(struct Actuator_ *d);   
    
    
    /// Function pointer to write to the actuator
    /// This function performs the necessary conversions and outputs to the IO cards to fulfill the actuators function
    /// @brief write to the actuator
    /// @param d pointer to the actuator structure
    /// @param value to be written to the actuator, the units of the value are stored in the unit field of the actuator structure   
    /// @return 0 for success, -1 for error
    int (*write)(struct Actuator_ *d, double value); 
    
    /// Function pointer to remove function of the actuator
    /// This function performs the necessary cleanup operations of the actuator such as releasing any resources that have been taken up by the actuator, this function is called before the end of the application or when the actuator is removed from the application
    /// @brief remove actuator
    /// @param d pointer to the actuator structure
    /// @return 0 for success, -1 for error
    int (*remove)(struct Actuator_* d);
    
    /// Function pointer to reset the actuator
    /// This function performs the necessary operations to reset the actuator should it be needed to reset
    /// @brief reset actuator
    /// @param d pointer to the actuator structure
    /// @return 0 for success, -1 for error
    int (*reset)(struct Actuator_* d);
    
    /// Function pointer to set parameters of the actuator
    /// This function is used to set the parameters of the actuator
    /// @brief set a parameter of the actuator
    /// @param d pointer to the actuator structure
    /// @param parameter, number of the parameter ID to be written to the actuator
    /// @param value to be written to the parameter, parameters may be offsets or coefficients to be utilized in the actuator
    /// @return 0 for success, -1 for error
    int (*setParameter)(struct Actuator_* d,int parameter, double value);
	
};

typedef struct Actuator_ Actuator;


/// Function to setup the actuator
/// This function is used to setup the fields of the actuator structure
/// @brief setup actuator
/// @param d pointer to the actuator structure
/// @param name contains name of the actuator as a string
/// @param units contains the units of the actuator as a string
/// @param init funtion pointer to the function to initialize the actuator
/// @param write function pointer to the function to write to the actuator
/// @param remove function pointer to the function to remove or delete the actuator
/// @param reset function pointer to the function to reset the actuator
/// @param setParameter function pointer to the function to set the parameters of the actuator
/// @return 0 for success, -1 for error
int setupActuator(Actuator * d,
                  char* name,
                  char* units, 

                  int (*init)( Actuator *d),
                  int (*write)( Actuator *d, double value),
                  int (*remove)(Actuator* d),
                  int (*reset)(Actuator* d),
                  int (*setParameter)(Actuator* d, int parameter, double value)
                  ){
    
	d->name = name;
	d->units = units;

    d->write = write;
    d->remove = remove;
    d->reset = reset;
    d->setParameter = setParameter;
    
    return 0;

}

#endif