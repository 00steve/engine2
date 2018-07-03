#ifndef MATH_2D_H
#define MATH_2D_H

#include "Double2.h"
#include "LineSegment.h"
#include "AABB.h"
#include "Circle.h"

/*
REFERENCES:
https://martin-thoma.com/how-to-check-if-two-line-segments-intersect/

AABB intersection
http://stackoverflow.com/questions/306316/determine-if-two-rectangles-overlap-each-other
*/

class Math2d{
private:

    static double EPSILON;
public:


    static Double2 ClosestPointOnLineSegment(LineSegment lineSegment,Double2 point);

    /*returns the closest point on a line that is represented by a line segment with
    two points that lie on the line and the point to measure from.*/
    static Double2 ClosestPointOnLine(LineSegment lineSegment,Double2 point);

    /*check if a point is on a line.*/
    static bool IsPointOnLine(LineSegment lineSegment,Double2 point);
    /*check if a point is on the right side of a line. From the line's perspective,
    is the point to the left of it or to the right. If it is to the right, it
    returns true, otherwise it returns false. A very simple example would be a line
    that extends from 0,0 to 10,0. Any point with a positive y would be to the left,
    and any point with negative y would be to the right. If the line was from 0,0
    to -10,0, any point with a positive y would be to the right and any point with
    a negative y would be to the left.*/
    static bool IsPointRightOfLine(LineSegment lineSegment,Double2 point);

    static bool DoesLineSegmentIntersectCircle(LineSegment lineSegment,Circle circle);

    /*check if a line segment intersects a line. The line is represented by a line
    segment object, but be assured, it is a line.*/
    static bool DoesLineSegmentIntersectLine(LineSegment line,LineSegment lineSegment);

    static bool DoLineSegmentsIntersect(LineSegment a,LineSegment b);

    static bool DoAABBsIntersect(AABB a,AABB b);

    static AABB AABBFromLineSegment(LineSegment lineSegment);

};
#endif // MATH_2D_H
