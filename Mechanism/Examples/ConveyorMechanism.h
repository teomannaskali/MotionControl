/** @file ConveyorMechanism.h
@brief This file creates the conveyor mechanism that is utilized in a Micro Factory. The conveyor has 1 motor, 3 stoppers and 3 sensors to sense trays at the stopper locations. 
 */


#include "Mechanism.h"

#include "ConveyorStopper.h"

#include "ConveyorMotor.h"

#include "ConveyorStation.h"

//Prefix ConveyorMechanism
//Prefix CM

///Enumeration of the conveyors actuators
enum ConveyorMechanismActuators{
    CM_Stopper1,
    CM_Stopper2,
    CM_Stopper3,
    CM_Motor
};

///Enumeration of the conveyors sensors
enum ConveyorMechanismSensors{
    CM_Station1,
    CM_Station2,
    CM_Station3

};

///MechanismParameters define what the parameters of this mechanism
// enum ConveyorMechanismParameters {};

enum ConveyorMechanismInputs{
    ConveyorSpeed ,
    ConveyorStation
};

///MechanismStates define what the states of this mechanims are
enum ConveyorMechanismStates {
    Station
    
};

/// MechanismStateMachineStates are the states of the State Machine within the mechanism. The state machine of the mechanims is utilized to command the mechanism from one state to the other. The default states of the state machine are inactive and initialize. Depending on the needs of the mechanism the states should also include following position references and following speed references
enum ConveyorStateMachineStates{
    CM_Inactive,
    CM_Initialize,
    CM_MoveTo,
    CM_Move
    ///fill in the other states
};

int loopConveyorMechanism(Mechanism * M){

    

    switch (M->StateMachine) {
        case CM_Initialize:{
            /// Perform initialization of actuators sensors axes etc...
            break;
        };
        case CM_Inactive:{
            //Stop Conveyor and stoppers
        /*    M->Actuators[CM_Motor].write(&M->Actuators[CM_Motor],0);
            M->Actuators[CM_Stopper1].write(&M->Actuators[CM_Stopper1],0);
            M->Actuators[CM_Stopper2].write(&M->Actuators[CM_Stopper2],0);
            M->Actuators[CM_Stopper3].write(&M->Actuators[CM_Stopper3],0);
           */ 
            
        }
        
        case CM_MoveTo:{
            printf("Moving conveyor to %d", (int) M->input[ConveyorStation]);
           // M->Actuators[0].write(&M->Actuators[0],M->Parameters[speed]);
            
            
        
        }
        case CM_Move: {
            
         //   M->Actuators[0].write(&M->Actuators[0],M->Parameters[speed]);
        }
            
        default:
            break;
    }
    
    
    /// get reference for the manipulator
    
    /// Transform the coordinate references to axis references
    
    /// Command axees
    
    
    return 0;
}

/// Setup Converor  function is used to assign values and fill the actuators within the mechanism structure
int setupConveyor( Mechanism * m){
    
/*    setupActuator(&(m->Actuators[Motor]),"Motor", "m/s", initConveyorMotor, writeConveyorMotor,
                  removeConveyorMotor,
                  resetConveyorMotor,
                  setConveyorMotorParameter);
    // Initialize Actuators
    m->Actuators[Motor].outDIO[0] = 0;
    
*/
    
    // Initialize Sensors
    
    
    
    return 0;

}

int setConveyorMoveTo(Mechanism * M, int station, double speed){
    M->input[ConveyorStation] = (int)station;
    M->input[ConveyorSpeed] = speed;
    M->StateMachine = CM_MoveTo;

}