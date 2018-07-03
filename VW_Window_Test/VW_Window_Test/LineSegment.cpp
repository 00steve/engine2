#include "stdafx.h"
#include "LineSegment.h"

LineSegment::LineSegment(Double2 a,Double2 b) :
        AABB(Double2(a.x < b.x ? a.x:b.x,a.y>b.y ? a.y:b.y),Double2(a.x>b.x?a.x:b.x,a.y<b.y?a.y:b.y)),
        a(a),
        b(b)
        {
    //constructor code
}
LineSegment::LineSegment(double aX,double aY,double bX,double bY) :
        AABB(Double2(aX<bX?aX:bX,aY>bY?aY:bY),Double2(aX>bX?aX:bX,aY<bY?aY:bY)),
        a(Double2(aX,aY)),
        b(Double2(bX,bY))
        {
    //constructor code
}


void LineSegment::UpdateAABB(){
}

Double2 LineSegment::A(){ return a; }
Double2 LineSegment::B(){ return b; }
