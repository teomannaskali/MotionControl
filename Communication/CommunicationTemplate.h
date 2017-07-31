

// Incoming Communication Structure
struct inputCommunication{
    double ConveyorSpeed;
    int ConveyorStation;
    
}inCommunication;


// Outgoing Communication Structure
struct outputCommunication{
    int x;
    
}outCommunication;




int InputCommunication(){
    
    //Use the InputCommunication Structure to disperse its elements
    

    
    int x;
    printf("Expet to receive x:");
    scanf("%d",&x );
    
   // inCommunication.x = x;
    
    
}

int OutputCommunication(){
    
    // Fill in the outputCommunication Structure
    
    printf("output x:%d\n", outCommunication.x);

}

int send(int ID, void*data, int size){
    

}
int receive(int ID, void *data, int size){
    

}