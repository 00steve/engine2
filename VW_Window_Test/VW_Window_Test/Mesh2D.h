#pragma once
#include "Drawable.h"
#include "Map.h"
#include "Double2.h"
#include "Int2.h"
#include <GL/glew.h>

class Mesh2D : public Drawable {
private:

	/*a map of other meshes that are linked to this mesh, creating a heirarchy.*/
	Map<Mesh2D*> features;
	
	Mesh2D* parent;

	/**/
	UnorderedList<unsigned int> *indices;
	UnorderedList<Double2> *vertices;
	double *vert;
	unsigned int *ind; 

	unsigned int vertexBufferObject;
	unsigned int vertexArrayObject;
	unsigned int elementBufferObject;


public:

	bool BindToGraphics();

	void Draw();

	/*builds and returns a simple mesh in the form of a grid, based on the arguments passed into the function. The size 
	is the actual width and height of the entire grid, the divisions are how many times the grid should be sliced on both 
	the x and y axis. Passing in a Int2(0,0) will result in a simple square.*/
	bool GenerateGrid(Double2 size, Int2 divisions);

	Mesh2D();
	~Mesh2D();




};

