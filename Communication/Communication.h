/** @file Communication.h
 * @brief This file defines the communication for the system.
 * 
 */



#ifndef COMMUNICATION
#define COMMUNICATION


int InputCommunication();
int OutputCommunication();

int send(int ID, void*data, int size);
int receive(int ID, void *data, int size);

#endif