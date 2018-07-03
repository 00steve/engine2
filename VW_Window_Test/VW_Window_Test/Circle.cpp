#include "stdafx.h"
#include "Circle.h"

double Circle::pi = 3.1415926536;

Circle::Circle(Double2 center,double radius) :
        AABB(Double2(center.x-radius,center.y+radius),Double2(center.x+radius,center.y-radius)),
        center(center),
        radius(radius)
        {
    //constructor code
}

double Circle::Circumference(){
    return pi*radius*radius;
}


Double2 Circle::Center(){
    return center;
}

double Circle::Radius(){
    return radius;
}

void Circle::Shift(Double2 offset){
    center += offset;
    topLeft += offset;
    bottomRight += offset;
    updated = true;
}
