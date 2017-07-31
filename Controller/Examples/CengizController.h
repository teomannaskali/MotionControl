

#include "Controller.h"

#define PARAMCOUNT 20
#define ORDER 5

enum ProportionalControllerParameters {Kp};

void loopProportional(Controller * c, double *current, double * ref, double * output){
    
    
//    printf("Controllera girdi\n");
//    printf("Ref %lf\n", *ref);
//    printf("current %lf\n", *current);
    
    
    c->S[0] = c->P[Kp] * (*ref - *current);  
    
    *output = c->S[0];
    
//    printf("Output %lf\n", * output);
}

void initProportionalController(Controller *c, double KpVal){
    c->P[Kp] = KpVal;
    
}