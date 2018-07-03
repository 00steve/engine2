#include "stdafx.h"
#include "AABB.h"


AABB::AABB() :
    topLeft(Double2(std::numeric_limits<double>::max(),std::numeric_limits<double>::min())),
    bottomRight(Double2(std::numeric_limits<double>::min(),std::numeric_limits<double>::max())){
}

AABB::AABB(Double2 topLeft,Double2 bottomRight) :
        topLeft(topLeft),
        bottomRight(bottomRight)
        {

}

double AABB::Top(){ return topLeft.y; }
double AABB::Bottom(){ return bottomRight.y; }
double AABB::Left(){ return topLeft.x; }
double AABB::Right(){ return bottomRight.x; }
Double2 AABB::Center(){ return (topLeft+bottomRight)*.5;}


bool AABB::Updated(){ return !(!updated || (updated = false)); }

void AABB::Shift(Double2 offset){
    topLeft += offset;
    bottomRight += offset;
}

bool AABB::Contains(const AABB other){
    return other.topLeft.x >= topLeft.x
        && other.topLeft.y <= topLeft.y
        && other.bottomRight.x <= bottomRight.x
        && other.bottomRight.y >= bottomRight.y;
}


AABB AABB::InverseLimits(){
    return AABB(Double2(std::numeric_limits<double>::max(),std::numeric_limits<double>::min()),
                  Double2(std::numeric_limits<double>::min(),std::numeric_limits<double>::max()));
}
