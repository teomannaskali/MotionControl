/** @file HWWrapper.h
 *  @brief THis file is a dummy for test purposes and only printsout Header File For the Hardware Wrappers of motion control projects
 *  This file is to be used as a template for the development of various projects that involve hardware
 *  Objective is to create a standardized hardware functions that have the same name in all projects
 *  
 *
 *  Created by Teoman Naskali on 14/10/10.
 *  Copyright Sabanci University 2010. All rights reserved.
 *
 */

#ifndef HWWRAPPER
#define HWWRAPPER

#include <stdio.h>

/// Initialize Hardware
/// @brief Initialize the hardware that will interface for the wrapper.
/// @return 0 for success, -1 for error.
int initHardware(){
    printf("Hardware initialized\n");
    return 0;
};

/// Delete Hardware
/// @brief Celanup and free the resoruces allocated for the hardware
/// @return 0 for success, -1 for error.
int deleteHardware(){
    printf("Hardware removed\n");
    return 0;
    

};

/// Initialize Encoder
/// @brief Initializes the specified encoder channel.
/// @param channel the encoder channel number
/// @return 0 for success, -1 for error
int initEnocder(int channel){
    printf("Encoder channel %d initialized\n", channel);
    return 0;

};

/// Set the Encoder value
/// @brief Sets a value to the specified encoder channel.
/// Used for homing the encoder channel
/// @param channel the encoder channel number
/// @param encvalue the encoder value to be set to the encoder
/// @return 0 for success, -1 for error
int setEncoder(int channel, int encvalue){

    printf("Encoder channel %d set to value %d\n", channel, encvalue);
    return 0;

}

/// Get Encoder Value
/// @brief Gets the pulse number in the encoder hardware.
/// @param channel is the channel number to be read
/// @return encoder pulses
int getEncoder(int channel){
    return 0;

}

/// Initialize Encoder Metric Reader
/// @brief Initializes the Encoder Metric Reader.
/// Encoder Metric Reader reads the encoder and returns a value that is converted to the desired metric, such as angles, radians, millimeters or micrometers etc
/// @param channel is the encoder channel number
/// @return encoder pulses
int initEncoderMetricReader(int channel){return 0;};

/// Set Enocder Metric Reader
/// @brief Sets the conversion factor for the Encoder Metric Reader.
/// @param channel channel number
/// @param enc2metric the conversion factor from encoder pulses to the metric
/// @return 0 for success, -1 for error
int setEncoderMetricReader(int channel, float enc2metric){return 0;};

/// Get Encoder in Metric
/// @brief Gets the metric that has been converted from the encoder.
/// @param channel number
/// @return metric derived from pulses
float getEncoderInMetric(int channel){return 0;};

/// Initialize Velocity Reader
/// @brief Initializes the Velocity Reading fucntion.
/// Calculates or estimates the velocity using hardware
/// @param channel channel number
/// @return 0 for success, -1 for error
int initVelocityReader(int channel){return 0;};

/// Get Velocity
/// @brief Gets the Velocity that has been calculate by the hardware.
/// @param channel channel number
/// @return velocity
float getVelocity(int channel){return 0;};

/// Initialize Analog Output
/// @brief Initializes the Analog output circuit.
/// @param channel channel number
/// @return 0 for success, -1 for error
int initAnalogOutput(int channel){return 0;};

/// Set Analog Output
/// @brief Sets the value for analog output.
/// @param Volts output value in volts
/// @return 0 for success, -1 for error
int setAnalogOutput(int channel, float Volts){
    
    printf("Analog output channel %de set to %f volts", channel, Volts);
    return 0;};

/// Initialize Analog Inputs
/// @brief Initializes the Analog Input circuits.
/// @param channel channel number
/// @return 0 for success, -1 for error
int initAnalogInput(int channel){return 0;};

/// Get Analog Input
/// @brief Gets the Analog input.
/// @param channel channel number
/// @return Analog input in volts
float getAnalogInput(int channel){return 0;};

/// Initialize Digital Input
/// @brief Initializes the Digital Input Circuits.
/// @param channel channel number
/// @return 0 for success, -1 for error
int initDigitalInput(int channel){return 0;};

/// Get Digital Input
/// @brief Gets the Digitial input.
/// @param channel channel number
/// @return 0 for success, -1 for error
int getDigitalInput(int channel){return 0;};

/// Initialize Digital Output
/// @brief Initializes the Digital Output circuit.
/// @param channel channel number
/// @return 0 for success, -1 for error
int initDigitalOutput(int channel){return 0;};

/// Set Digital Output
/// @brief Sets the Digital Output.
/// @param channel channel number
/// @param value output value in boolean
/// @return 0 for success, -1 for error
int setDigitalOutput(int channel, int value){
	

	// ds40010bitout(channel, value);
	
	
	
	return -1;
};

/// Initialize PWM
/// @brief Initializes the PWM circuit.
/// @param channel channel number
/// @return 0 for success, -1 for error
int initPWM(int channel){return 0;};

/// Set PWM
/// @brief Sets the PWM output value.
/// @param value, specify value
/// @return 0 for success, -1 for error
int setPWM(int channel, int value){return 0;};

#endif