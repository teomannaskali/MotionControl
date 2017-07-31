/** @file MechanismTemplate.h
@brief This file is a template for the creation of a mechanism. The functions within must be fulfilled and the state machine configured in order to provide functionnality to the mechanism.
 */



#include "Mechanism.h"


///MechanismParameters define what the parameters of this mechanism 
enum MechanismParameters {
    
    };

///MechanismStates define what the states of this mechanims are
enum MechanismStates {
    StateMachine
    };

/// MechanismStateMachineStates are the states of the State Machine within the mechanism. The state machine of the mechanims is utilized to command the mechanism from one state to the other. The default states of the state machine are inactive and initialize. Depending on the needs of the mechanism the states should also include following position references and following speed references
enum MechanismStateMachineStates{
    initialize,
    inactive,
    loop
    ///fill in the other states
}

int loopMechanism(Mechanism * M, double ref[MANIPULATORREF]){
    
    switch (M->States[MechanismStates.StateMachine]) {
        case :{
            /// Perform initialization of actuators sensors axes etc...
            break;
        }

        default:
            break;
    }
    
    
    /// get reference for the manipulator
    
    /// Transform the coordinate references to axis references
    
    /// Command axees
    
    
    return 0;
}


// Code for custom functions should be added here.