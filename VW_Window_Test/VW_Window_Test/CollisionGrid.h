#ifndef COLLISION_GRID_H
#define COLLISION_GRID_H

#include <iostream>
#include "AABB.h"

#include "UnorderedList.h"


class CollisionGrid : public AABB{

private:
    CollisionGrid *parent;
    CollisionGrid *subGrids[4];

    UnorderedList<AABB*> shapes;

    void Setup();

    static unsigned int depth;

public:
    CollisionGrid(AABB bounds);
    CollisionGrid(AABB bounds,CollisionGrid *parent);
    ~CollisionGrid();


    bool Add(AABB* shape);

    UnorderedList<AABB*> UpdateShapeTree(UnorderedList<AABB*>);

    unsigned int SubShapeCount();
    bool SubGrids();
    CollisionGrid SubGrid(int index);
    CollisionGrid *Parent();
    UnorderedList<AABB*> Shapes();

    UnorderedList<AABB*> BubbleUpSubShapes(UnorderedList<AABB*> shapes);


};




#endif // COLLISION_GRID_H
