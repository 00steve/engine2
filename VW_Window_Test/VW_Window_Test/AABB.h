#ifndef AABB_H
#define AABB_H

#include "Double2.h"
#include <limits>

/*
Axis-aligned bounding box

*/


class AABB {
protected:
    Double2 topLeft;
    Double2 bottomRight;
    bool updated;
public:

    AABB();
    AABB(Double2 topLeft,Double2 bottomRight);

    double Top();
    double Bottom();
    double Left();
    double Right();
    Double2 Center();

    bool Updated();

    virtual void Shift(Double2 offset);
    bool Contains(const AABB other);


    /*use this AABB constructor if you need a starting
    place to get max of two AABBs.*/
    static AABB InverseLimits();

};

#endif // BOUNDING_BOX_H
