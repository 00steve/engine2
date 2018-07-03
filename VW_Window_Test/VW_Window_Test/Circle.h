#ifndef CIRCLE_H
#define CIRCLE_H

#include "Double2.h"
#include "AABB.h"

class Circle : public AABB{
private:
    Double2 center;
    double radius;
    static double pi;

public:

    Circle(Double2 center,double radius);

    double Circumference();
    Double2 Center();
    double Radius();

    virtual void Shift(Double2 offset);

};




#endif // CIRCLE_H
