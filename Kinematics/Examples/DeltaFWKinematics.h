/** @file DeltaFWKinematics.h
 * @brief Implementation of the Delta Robot Kinematics.
 
 * Forward kinematics of a delta robot are implemented in this file *
 */

#include "Kinematics.h" ///< Included to obtain the Kinematics struct.
#include <math.h>

/// Prefix DeltaFWKinematics

/// Robot paramters, used to configure the Kinematics


/// DeltaKInematicsParameters, this enum defines the pramters array, which contains the arm lengths, base redius, ancelle raidus, arm orientations and zoffset.
enum DeltaFWKinematicsParameters {
	DeltaLA , ///< Upper Arm Lenght
	DeltaLB , ///< Lower Arm Length
	DeltaRA , ///< Base Radius
	DeltaRB , ///< Nacelle Radius
	DeltaTheta1 ,   ///< Arm orientation angle 1
	DeltaTheta2 ,   ///< Arm orientation angle 2
	DeltaTheta3 ,   ///< Arm orientation angle 3
    
    DeltaZofset   ///< Offset for the nozzle int he vertical axis
    
};




/// Inputs to the Delta robot forward kinematics array
enum DeltaFWKinematicsInput{
    DeltaFWAlpha1, ///<alpha1 coordinate in joint space, input
    DeltaFWAlpha2, ///<alpha2 cooridnate in joint space, input
    DeltaFWAlpha3  ///<alpha3 coordinate in joint space, input
    
};

/// Outputs of the delta robot forward kinematics.
enum DeltaFWKinematicsOutput{
    DeltaFWX,///< X coordinate in task space
    DeltaFWY,///< Y coordinate in task space
    DeltaFWZ ///< Z coordinate in task space
};



/**
 * Delta Robot Forward Kinematics
 * @param c pointer to a Kinematics structure
 * @return return values are contained in the Kinematics structures output array
*/
void loopDeltaFWKinematics(Kinematics * k){
   
    
    
        double alpha1rad = (k->input[alpha1] + 30.0)*(pi/180);
        double alpha2rad = (k->input[alpha2] + 30.0)*(pi/180);
        double alpha3rad = (k->input[alpha3] + 30.0)*(pi/180);
        
        double R = k->paramters[DeltaRA] - k->parameters[DeltaRB];
        
        double LA_2 = pow(k->paramters[DeltaLA],2);
        double LB_2 = pow(k->paramters[DeltaLB],2);
        double R_2 = pow(R,2);
        
        double D1 = -LB_2 + LA_2 + R_2 + 2*R*k->paramters[DeltaLA]*cos(alpha1rad);
        double E1 = 2*(R+k->paramters[DeltaLA]*cos(alpha1rad))*cos(k->paramters[DeltaTheta1]);
        double F1 = 2*(R+k->paramters[DeltaLA]*cos(alpha1rad))*sin(k->paramters[DeltaTheta1]);
        double G1 = -2*k->paramters[DeltaLA]*sin(alpha1rad);
        
        double D2 = -LB_2 + LA_2 + R_2 + 2*R*k->paramters[DeltaLA]*cos(alpha2rad);
        double E2 = 2*(R+k->paramters[DeltaLA]*cos(alpha2rad))*cos(k->paramters[DeltaTheta2]);
        double F2 = 2*(R+k->paramters[DeltaLA]*cos(alpha2rad))*sin(k->paramters[DeltaTheta2]);
        double G2 = -2*k->paramters[DeltaLA]*sin(alpha2rad);
        
        double D3 = -LB_2 + LA_2 + R_2 + 2*R*k->paramters[DeltaLA]*cos(alpha3rad);
        double E3 = 2*(R+k->paramters[DeltaLA]*cos(alpha3rad))*cos(k->paramters[DeltaTheta3]);
        double F3 = 2*(R+k->paramters[DeltaLA]*cos(alpha3rad))*sin(k->paramters[DeltaTheta3]);
        double G3 = -2*k->paramters[DeltaLA]*sin(alpha3rad);
        
        double H1 = E1*G2 - E1*G3 - E2*G1 + E2*G3 + E3*G1 - E3*G2;
        double H2 = -E1*F2 + E1*F3 + E2*F1 - E2*F3 - E3*F1 + E3*F2;
        double H3 = -E1*D2 + E1*D3 + E2*D1 - E2*D3 - E3*D1 + E3*D2;
        double H4 = F1*D2 - F1*D3 - F2*D1 + F2*D3 + F3*D1 - F3*D2;
        double H5 = -F1*G2 + F1*G3 + F2*G1 - F2*G3 - F3*G1 + F3*G2;
        
        double H1_2 = pow(H1,2);
        double H2_2 = pow(H2,2);
        double H3_2 = pow(H3,2);
        double H4_2 = pow(H4,2);
        double H5_2 = pow(H5,2);
        
        double L = ((H5_2 + H1_2)/H2_2) + 1;
        double M = 2*((H5*H4 + H1*H3)/H2_2) - ((H5*E1 + H1*F1)/H2) - G1;
        double Q = ((H4_2 + H3_2)/H2_2) - ((H4*E1 + H3*F1)/H2) + D1;
        
        double M_2 = pow(M,2);
        
        double z_out = (-M - sqrt(M_2 - 4*L*Q))/(2*L);
        
        double x_out = (z_out*H5)/H2 + H4/H2;
        double y_out = (z_out*H1)/H2 + H3/H2;
        
        k->output[DeltaFWX] = x_out;
        k->output[DeltaFWY] = y_out;
        k->output[DeltaFWZ] = z_out;
    
    
}






