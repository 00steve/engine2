#include "stdafx.h"
#include "CollisionGrid.h"


unsigned int CollisionGrid::depth = 0;


void CollisionGrid::Setup(){
    subGrids[0] = NULL;
    subGrids[1] = NULL;
    subGrids[2] = NULL;
    subGrids[3] = NULL;
}

CollisionGrid::CollisionGrid(AABB bounds) :
        AABB(bounds),
        parent(NULL){
    Setup();
}


CollisionGrid::CollisionGrid(AABB bounds,CollisionGrid* parent) :
        AABB(bounds),
        parent(parent){
    Setup();
}

CollisionGrid::~CollisionGrid(){
    //std::cout << "d\n";
    if(subGrids[0]){
        delete []subGrids;
    }
}

bool CollisionGrid::Add(AABB* shape){
    if(!Contains(*shape)) return false;
    //std::cout<<"-";
    if(SubShapeCount()>1){
        //std::cout<<"|"<<(subGrids[0]?"s":"n");
        if(!subGrids[0]){
            std::cout <<"+";
            Double2 center = (topLeft + bottomRight) * .5;
            subGrids[0] = new CollisionGrid(AABB(topLeft,center));
            subGrids[1] = new CollisionGrid(AABB(Double2(center.x,topLeft.y),Double2(bottomRight.x,center.y)));
            subGrids[2] = new CollisionGrid(AABB(Double2(topLeft.x,center.y),Double2(center.x,bottomRight.y)));
            subGrids[3] = new CollisionGrid(AABB(center,bottomRight));
            int s = shapes.Count();
            int i;
            while( s-->0 ){
                i=4;
                while(i --> 0){
                    //std::cout << " (g" << i << ")";
                    if(!subGrids[i]->Add(shapes[s])) {
                        std::cout << "\\";
                        continue;
                    }
                    shapes.Cut(shapes[s]);
                    break;
                }
            }

        } else {

        }

    }
    if(subGrids[0]){
        int i=4;
        while(i-->0){
            if(!subGrids[i]->Add(shape)){
                std::cout << ">";
                    continue;
            }
            //std::cout << "added shape\n";
            return true;
        }
        //std::cout << "couldn't add shape to subgrid\n";
    }
    std::cout << "+ " << depth << "\n";
    shapes.Push(shape);
    return true;
}

UnorderedList<AABB*> CollisionGrid::UpdateShapeTree(UnorderedList<AABB*> insertShapes){
    ++depth;
    int i=4;
    if(subGrids[0]){
        while(i-->0){
            insertShapes = subGrids[i]->UpdateShapeTree(insertShapes);
        }
    }
    i=insertShapes.Count();
    while(i-->0){
        if(Add(insertShapes[i])){
            insertShapes.Cut(insertShapes[i]);
        } else {
            //std::cout << "couldn't insert shape at iteration : " << depth << std::endl;
        }
    }

    //update existing shapes at this depth, check to see if they are
    //still contained in this grid square. If they are not, send them
    //along to the parent grid. If they are, check to see if they can
    //be placed in any children grids.
    i=shapes.Count();
    while(i-->0){
        if(!shapes[i]->Updated()) continue;
        if(Contains(*(shapes[i]))){
            if(subGrids[0]){
                ++depth;
                for(int q=0;q<4;q++){
                    //std::cout << ">";
                    if(!subGrids[q]->Add(shapes[i])) continue;
                    shapes.Cut(shapes[i]);
                }
                --depth;
            }
        } else {
            std::cout << "<";
            insertShapes.Push(shapes[i]);
            shapes.Cut(shapes[i]);
        }
    }
    if(subGrids[0]!=NULL && SubShapeCount()<3){
        shapes = BubbleUpSubShapes(shapes);
        delete [] subGrids;
        for(int i=0;i<4;i++){
            subGrids[i] = NULL;
        }
    }

    --depth;
    return insertShapes;
}

unsigned int CollisionGrid::SubShapeCount(){
    unsigned int t = 0;
    if(subGrids[0]){
        t += subGrids[0]->SubShapeCount();
        t += subGrids[1]->SubShapeCount();
        t += subGrids[2]->SubShapeCount();
        t += subGrids[3]->SubShapeCount();
    }
    return shapes.Count() + t;
}
bool CollisionGrid::SubGrids(){ return subGrids[0]; }
CollisionGrid CollisionGrid::SubGrid(int index){ return *subGrids[index]; }

CollisionGrid* CollisionGrid::Parent(){
    return parent;
}


UnorderedList<AABB*> CollisionGrid::Shapes(){
    return shapes;
}


UnorderedList<AABB*> CollisionGrid::BubbleUpSubShapes(UnorderedList<AABB*> shapesList){
    int i=shapes.Count();
    while(i-->0){
        shapesList.Push(shapes[i]);
        shapes.Cut(shapes[i]);
    }

    if(subGrids[0]){
        shapesList = subGrids[0]->BubbleUpSubShapes(shapesList);
        shapesList = subGrids[1]->BubbleUpSubShapes(shapesList);
        shapesList = subGrids[2]->BubbleUpSubShapes(shapesList);
        shapesList = subGrids[3]->BubbleUpSubShapes(shapesList);
    }
    return shapesList;

}
