#include "stdafx.h"
#include "Double2.h"


Double2::Double2() : x(0), y(0) {

}


Double2::Double2(double x,double y) :
        x(x),
        y(y)
        {
    //stuff
}

double Double2::Length(){
    return sqrt(x*x+y*y);
}
double Double2::Magnitude(){
    return x*x+y*y;
}
Double2 Double2::Normal(){
    double l = Length();
    return Double2(x/l,y/l);
}
Double2 Double2::Normalize(){
    double l = Length();
    x /= l;
    y /= l;
    return Double2(x,y);
}
Double2 Double2::RightAngle(){
    return Double2(y,-x).Normalize();
}
double Double2::Angle(const Double2 other){
    return acos((x*other.x + y*other.y) / (sqrt(x*x+y*y) * sqrt(other.x*other.x+other.y*other.y)) );
}

double Double2::operator *(const Double2 other){
    return x*other.x + y*other.y;
}
double Double2::operator ^(const Double2 other){
    return x * other.y - y * other.x;
}

Double2 Double2::operator +(const Double2 other){
    return Double2(x+other.x,y+other.y);
}
Double2 Double2::operator +=(const Double2 other){
    x += other.x;
    y += other.y;
    return *this;
}
Double2 Double2::operator -(const Double2 other){
    return Double2(x-other.x,y-other.y);
}
Double2 Double2::operator -=(const Double2 other){
    x -= other.x;
    y -= other.y;
    return *this;
}

Double2 Double2::operator *(const double scaler){
    return Double2(x*scaler,y*scaler);
}
Double2 Double2::operator /(const double scaler){
    return Double2(x/scaler,y/scaler);
}
