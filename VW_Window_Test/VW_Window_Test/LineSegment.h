#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "Double2.h"
#include "AABB.h"

class LineSegment : public AABB{
private:
    Double2 a;
    Double2 b;

    void UpdateAABB();

public:

    LineSegment(Double2 a,Double2 b);
    LineSegment(double aX,double aY,double bX,double bY);

    Double2 A();
    Double2 B();
};





#endif
