#include "stdafx.h"
#include "Math2d.h"
double Math2d::EPSILON = .004;


Double2 Math2d::ClosestPointOnLineSegment(LineSegment lineSegment,Double2 point){
    Double2 ab = lineSegment.B() - lineSegment.A();
    double distance = (point - lineSegment.A()) * ab / ab.Magnitude();
    if(distance < 0) return lineSegment.A();
    if(distance > 1) return lineSegment.B();
    return lineSegment.A() + ab*distance;
}

Double2 Math2d::ClosestPointOnLine(LineSegment lineSegment,Double2 point){
    Double2 ab = lineSegment.B() - lineSegment.A();
    return lineSegment.A() + ab*((point - lineSegment.A()) * ab / ab.Magnitude());
}

bool Math2d::IsPointOnLine(LineSegment lineSegment,Double2 point){
    return fabs((lineSegment.B()-lineSegment.A())^(point-lineSegment.A())) < EPSILON;
}

bool Math2d::IsPointRightOfLine(LineSegment lineSegment,Double2 point){
    return ((lineSegment.B()-lineSegment.A())^(point-lineSegment.A())) < 0;
}

bool Math2d::DoesLineSegmentIntersectLine(LineSegment line,LineSegment lineSegment){
    return IsPointOnLine(line,lineSegment.A())
        || IsPointOnLine(line,lineSegment.B())
        || (IsPointRightOfLine(line,lineSegment.A()) ^ IsPointRightOfLine(line,lineSegment.B()));
}


bool Math2d::DoesLineSegmentIntersectCircle(LineSegment lineSegment,Circle circle){
    if(!DoAABBsIntersect((AABB)lineSegment,(AABB)circle)) return false;
    return (Math2d::ClosestPointOnLineSegment(lineSegment,circle.Center()) - circle.Center()).Length() < circle.Radius();
}

/*
public boolean doLinesIntersect(LineSegment a, LineSegment b) {
    Point[] box1 = a.getBoundingBox();
    Point[] box2 = b.getBoundingBox();
    return doBoundingBoxesIntersect(box1, box2)
            && lineSegmentTouchesOrCrossesLine(a, b)
            && lineSegmentTouchesOrCrossesLine(b, a);
}
*/
bool Math2d::DoLineSegmentsIntersect(LineSegment a,LineSegment b){
    //AABB abox = AABBFromLineSegment(a);
    //AABB bbox = AABBFromLineSegment(b);

    return DoAABBsIntersect((AABB)a,(AABB)b)
        && DoesLineSegmentIntersectLine(a,b)
        && DoesLineSegmentIntersectLine(b,a);

}


bool Math2d::DoAABBsIntersect(AABB a,AABB b){
    return !(a.Left() >= b.Right() || a.Right() <= b.Left()
             || a.Top() <= b.Bottom() || a.Bottom() >= b.Top());
}

/*if (RectA.Left < RectB.Right && RectA.Right > RectB.Left &&
     RectA.Top < RectB.Bottom && RectA.Bottom > RectB.Top )
bool Math2d::DoAABBsIntersect(AABB a,AABB b){
    return a.Left() < b.Right() && a.Right() > b.Left() && a.Top()<b.Bottom() && a.Bottom() > b.Top();
}
*/
AABB Math2d::AABBFromLineSegment(LineSegment lineSegment){
    bool ax = lineSegment.A().x > lineSegment.B().x;
    bool ay = lineSegment.A().y > lineSegment.B().y;
    return AABB(Double2(ax?lineSegment.B().x:lineSegment.A().x,ay?lineSegment.A().y:lineSegment.B().y),
                Double2(ax?lineSegment.A().x:lineSegment.B().x,ay?lineSegment.B().y:lineSegment.A().y));
}
