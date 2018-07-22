#ifndef DOUBLE_TWO_H
#define DOUBLE_TWO_H

#include <math.h>
#include "Int2.h"

class Double2{
public:
    double x;
    double y;

	Double2();
    Double2(double x,double y);

    /*Assuming that the double2 is a vector from 0,0 to x,y, get the direct
    distance from 0,0 to x,y.*/
    double Length();
    /*magnitude of the length is the length^2, basically, the function that
    finds the length can be run, but without having to sqrt() the whole thing.*/
    double Magnitude();
    /*gets the angle in radians between the two points, assuming they are vectors,
    both originating at 0,0*/
    double Angle(const Double2 other);


    Double2 Normal();
    Double2 Normalize();
    Double2 RightAngle();

    /*dot product*/
    double operator *(const Double2 other);

    /*cross product
    http://allenchou.net/2013/07/cross-product-of-2d-vectors/
    */
    double operator ^(const Double2 other);

    Double2 operator +(const Double2 other);
    Double2 operator +=(const Double2 other);
    Double2 operator -(const Double2 other);
    Double2 operator -=(const Double2 other);

	Double2 operator +(const Int2 other);
	Double2 operator +=(const Int2 other);
	Double2 operator -(const Int2 other);
	Double2 operator -=(const Int2 other);

    Double2 operator *(const double scaler);
    Double2 operator /(const double scaler);

	/*atomic divide, meaning divide the x by the x divisor, y by 
	the y divisor. Don't generate a matrix, like if a 2x1 matrix was divided
	by a 2x1 matrix.*/
	Double2 AD(const Int2 divisor);
};

typedef Double2 Point;

#endif // DOUBLE_TWO_H
