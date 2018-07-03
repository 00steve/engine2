#ifndef NGON_H
#define NGON_H

#include "Double2.h"
#include "LineSegment.h"
#include "UnorderedList.h"
#include "AABB.h"
#include <limits>

class NGon : public AABB{
private:

    UnorderedList<Point> points;

    AABB CalculateBounds(UnorderedList<Point> segments);


public:

    NGon();

    void AddPoints(UnorderedList<Point> points);

};



#endif // NGON_H
