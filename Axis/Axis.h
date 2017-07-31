
#ifndef AXIS 
#define AXIS

#include "Actuator.h"
#include "Sensor.h"
#include "Filter.h"
#include "Controller.h"
//#include "Observer.h"


#define AXISSENSORNUM 1
#define AXISACTUATORNUM 1
#define AXISFILTERNUM 1
#define AXISOBSERVERNUM 1
#define AXISCONTROLLERNUM 1
#define AXISPARAMTERNUM 10
#define AXISSTATENUM 5
#define AXISINPUTNUM 6
#define AXISOUTPUTNUM 6


struct Axis_{
	
    char* name;
	
    Sensor Sensors[AXISSENSORNUM];
    Actuator Actuators[AXISACTUATORNUM] ;
    Filter Filters[AXISFILTERNUM];
//    Observer Observers[AXISOBSERVERNUM];
    Controller Controllers[AXISCONTROLLERNUM];
    
 
    double input[AXISINPUTNUM];
    double output[AXISOUTPUTNUM];
    
    double parameter[AXISPARAMTERNUM]; ///< Parameters of the Mechanism, used to configure the Mechanism
    double state[AXISSTATENUM];         ///< States of the Mechanism, used to store internal data of the Mechanism
    
    
    int enable;

    int (*init)(struct Axis_ *a);
    int (*step)(struct Axis_ *a, double reference);
    int (*remove)(struct Axis_* a);
    int (*reset)(struct Axis_* a);
    
	
};

typedef struct Axis_ Axis;

int setupAxis(Axis * a,
                    char* name,
                    int (*init)(struct Axis_ *a),
                    int (*step)(struct Axis_ *a, double reference),
                    int (*remove)(struct Axis_* a),
                    int (*reset)(struct Axis_* a)
                  ){
    
	a->name = name;
    a->init = init;
    a->step = step;
    a->remove = remove;
    a->reset = reset;
    
    return 0;
}

#endif