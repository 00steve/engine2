

#ifndef DOUBLE3_H
#define DOUBLE3_H

/*the Double3 class is a simple container for storing x,y,z double values
that are necessary for any 3d calculations. It includes basic functions
for performing math operations with double2 and double variables, as well
as some common functions like getting the length of the vector, or cross-
multiplication with other Double3 variables.*/

#include <limits>
#include <math.h>

class Double3 {
public:

	//store the x,y and z variables
    double x,y,z;

	//Double3 constructor, initialize all variables to zero
    //Double3();

	//constructor that assigns default values
    //Double3(double x,double y,double z);

    	//Double3 constructor, initialize all variables to zero
    Double3() : x(0),y(0),z(0) {
    }

	//constructor that assigns default values
    Double3(double x,double y,double z) :
    	x(x),
    	y(y),
    	z(z) {
    }


    //get the normal of the vector
    Double3 Normal();

	//convert the Double3 to its normalized length and return the value
    Double3 Normalize();

    /*returns the cross product of two Double3 vectors.*/
    Double3 operator ^ (const Double3 &f);

    /*returns the dot product of two Double3 vectors*/
    double	operator * (const Double3 &f);

    Double3 operator += (const Double3 &f);
    Double3 operator -= (const Double3 &f);
    Double3 operator + (const Double3 &f);
    Double3 operator - (const Double3 &f);

    Double3 operator *= (const double &d);
    Double3 operator * (const double &f);
    Double3 operator + (const double &f);
    Double3 operator - (const double &f);

    bool operator > (const double &f);
    bool operator < (const double &f);

    double Length();

    static Double3 infinity;
};



#endif

