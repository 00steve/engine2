
#include "stdafx.h"
#include "Double3.h"




    //get the normal of the vector
Double3 Double3::Normal() {
        double length = sqrt(x*x+y*y+z*z);
        return Double3(x / length , y / length, z / length );
    }

	//convert the Double3 to its normalized length and return the value
Double3 Double3::Normalize() {
        double length = sqrt(x*x+y*y+z*z);
        x /= length; y /= length; z /= length;
        return *this;
    }

    /*returns the cross product of two Double3 vectors.*/
    Double3 Double3::operator ^ (const Double3 &f) 	{ return Double3(y*f.z-z*f.y,z*f.x-x*f.z,x*f.y-y*f.x);}

    /*returns the dot product of two Double3 vectors*/
    double	Double3::operator * (const Double3 &f)	{ return x*f.x + y*f.y + z*f.z; }

    Double3 Double3::operator += (const Double3 &f) 	{ x += f.x; y += f.y; z += f.z; return *this; }
    Double3 Double3::operator -= (const Double3 &f) 	{ x -= f.x; y -= f.y; z -= f.z; return *this; }
    Double3 Double3::operator + (const Double3 &f) 	{ return Double3(x+f.x,y+f.y,z+f.z); }
    Double3 Double3::operator - (const Double3 &f) 	{ return Double3(x-f.x,y-f.y,z-f.z); }

    Double3 Double3::operator *= (const double &d) 	{ x *= d; y *= d; z *= d; return *this; }
    Double3 Double3::operator * (const double &f) 	{ return Double3(x*f,y*f,z*f); }
    Double3 Double3::operator + (const double &f) 	{ return Double3(x+f,y+f,z+f); }
    Double3 Double3::operator - (const double &f) 	{ return Double3(x-f,y-f,z-f); }

    bool Double3::operator > (const double &f) {
        if(x*x+y*y+z*z > f*f) return true;
        return false;
    }
    bool Double3::operator < (const double &f) {
        if(x*x+y*y+z*z < f*f) return true;
        return false;
    }

    double Double3::Length() { return sqrt(x*x+y*y+z*z); }


/*Double3 initialized to the largest
double values that the system supports*/
Double3 Double3::infinity = Double3(std::numeric_limits<double>::max(),std::numeric_limits<double>::max(),std::numeric_limits<double>::max());

/*given two Double3 values, it returns the greater of each double value
as a new Double3*/
inline Double3 Double3_greater(const Double3 &a,const Double3 &b) {
    return Double3((a.x>b.x?a.x:b.x),(a.y>b.y?a.y:b.y),(a.z>b.z?a.z:b.z));
}

/*given two Double3 values, it returns the lesser of each double value
as a new Double3*/
inline Double3 Double3_lesser(const Double3 &a,const Double3 &b) {
    return Double3((a.x<b.x?a.x:b.x),(a.y<b.y?a.y:b.y),(a.z<b.z?a.z:b.z));
}

