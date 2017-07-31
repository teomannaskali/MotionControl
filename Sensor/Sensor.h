/** @file Sensor.h
 * @brief General definition of an sensor containing the data structures.
 * 
 */

#ifndef SENSOR 
#define SENSOR



#define SENSMAXIO 3 ///< Defines the number of maximum different types input or output IO channel access by a single sensor
#define SENSMAXIN 3     ///< Defines the maximum number of inputs all sensors may have
#define SENSMAXOUT 3    ///< Defines the maximum number of outputs all sensors may have
#define SENSMAXSTATES 5 ///< Define the maximum number of states that all sensors may have
#define SENSMAXPARAMETERS 4 ///< Define the maximum number of parameters that all sensors may have





/// Sensor structure contains all the parameters and states of the sesor. The sensor sturcutre also contains the input and output channel numbers for a sensor along with function pointers to functions of the sensor to initialize, read, reset and delete the sensor.
struct Sensor_{
	
	char* name; ///< String representing the name of the sensor
    char* unit; ///< String containing the units of the sensor
    
	int outDIO[SENSMAXIO];          ///<List of the digital output channels that the sensor may have
    int inDIO[SENSMAXIO];           ///<List of the digital input channels that the sensor may have
    int inADC[SENSMAXIO];           ///<List of the analog input channels that the sensor may have
    int outDAC[SENSMAXIO];          ///<List of the analog output channels that the sensor may have
    int inENC[SENSMAXIO];           ///<List of the encoder channels that the sensor may have
    
    double inputs
    
    double state[SENSMAXSTATES];            ///< States of the sensor, internal data to keep log of values or other necessary information on a sensor.
    double parameter[SENSMAXPARAMETERS];    ///< Parameters of the sensor, may include coefficients of offsets.

    double (*read)(struct Sensor_ *s);          ///< Function pointer to the function that will perform reading a sensor
    int (*setParameter)(struct Sensor_* s,int parameter, double value);    ///< Function pointer to the function that will set a parameter of the sensor. This function is used to set the different parameters of a sensor.
    
    int (*reset)(struct Sensor_* s);    ///< Function pointer to the function that will reset a sensor. May be used  in case of sensor errors.
    int (*remove)(struct Sensor_*s);    ///< Function pointer to the function that removes a sensor. This function is called when the application is shutting down or when the sensor is no longer needed and is removed.
};

typedef struct Sensor_ Sensor;


/// Function to setup the sensor
/// This function is used to setup the fields of the sensor structure, such as assigning the functions to it.
/// @brief setup sensor
/// @param s pointer to the sensor structure
/// @param name contains name of the sensor as a string
/// @param units contains the units of the sensor as a string
/// @param read function pointer to the function to read the values of the sensor
/// @param setParameter function pointer to the function to set the parameters of the sensor
/// @param reset function pointer to the function to reset the sensor
/// @param remove function pointer to the function to remove or delete the sensor
/// @return 0 for success, -1 for error
int setupSensor(Sensor* s, 
               char* name, 
               char * unit, 
               double (*read)(struct Sensor_ *s),
               int (*setParameter)(struct Sensor_* s,int parameter, double v),
               int (*reset)(struct Sensor_* s),
               int (*remove)(struct Sensor_*s)
               )
{
    
    s->name = name;
    s->unit = unit;
    s->read = read;
    s->setParameter = setParameter;
    s->reset = reset;
    s->remove = remove;
    
    return 0;
}

#endif