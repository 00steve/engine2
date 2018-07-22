#include "stdafx.h"
#include "Mesh2D.h"


bool Mesh2D::BindToGraphics() {


	//generate these shits in whatever order you want, they don't depend on each other yet.
	glGenBuffers(1, &vertexBufferObject);
	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &elementBufferObject);

	//glBindVertexArray(vertexArrayObject);
	//glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(Double2)*vertices->Count(), vert, GL_STATIC_DRAW);


	////bind the ebo buffer so that the indecies data can be set, and other properties set 
	////up like the glVertexAttribPointer. 
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	//


	////set the indicies that are used
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices->Count(), ind, GL_STATIC_DRAW);

	////call this before binding a different element array buffer, to set the settings
	//glVertexAttribPointer(0, indices->Count()/3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);
	//glEnableVertexAttribArray(0);






	glBindVertexArray(vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	glBufferData(GL_ARRAY_BUFFER, sizeof(double) * 12, vert, GL_DYNAMIC_DRAW);


	//bind the ebo buffer so that the indecies data can be set, and other properties set 
	//up like the glVertexAttribPointer. 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);



	//set the indicies that are used
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, ind, GL_STATIC_DRAW);

	//call this before binding a different element array buffer, to set the settings
	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);
	glEnableVertexAttribArray(0);





	return true;
}


void Mesh2D::Draw() {
	//ctr += .002;
	//verts[0] = -.5 + cos(ctr)*.1;
	//verts[1] = .5 + sin(ctr)*.1;
	//verts[6] = -.5;
	//verts[7] = -.6;
	//glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	//rebuild the buffer data after updating the vertex information
	//glBufferData(GL_ARRAY_BUFFER, sizeof(double) * 12, verts, GL_DYNAMIC_DRAW);
	
	//bind the element buffer before drawing
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	//The first argument specifies the mode we want to draw in, similar to glDrawArrays. 
	//2: Number of elements to draw. e.g. 6 indices so we want to draw 6 vertices in total.
	//glDrawElements(GL_TRIANGLES, indices->Count(), GL_UNSIGNED_INT, 0);
	glDrawElements(DrawMode(), 6, GL_UNSIGNED_INT, 0);
}


bool Mesh2D::GenerateGrid(Double2 size, Int2 divisions) {
	cout << "\nGENERATE GRID\n";
	vertices->Reset();

	int i = 0;
	int xCount = (2 + divisions.x);
	int yCount = (2 + divisions.y);
	int vCount = xCount * yCount;
	int indexCount = (divisions.x + 1) * (divisions.y + 1) * 6;
	cout << "Index count : " << indexCount << endl;
	Double2 cellSize = size.AD(divisions + 1);
	vert = new double[vCount * 3]();
	ind = new unsigned int[indexCount]();
	cout << "cell size : " << cellSize.x << "," << cellSize.y << endl;
	vertices = new UnorderedList<Double2>(vCount);
	i = 0;
	for (double y = 0; y < yCount; y++) {
		for (double x = 0; x < xCount; x++) {
			vertices->Push(Double2(x*cellSize.x, y*cellSize.y));
			vert[i++] = x * cellSize.x;
			vert[i++] = y * -cellSize.y;
			vert[i++] = 0; //z-index
		}
	}

	cout << "\nGenerated vertices:\n";
	for (i = 0; i < vCount; i++) {
		cout << "[" << i << "]\t" << vert[i*3] << ",\t" << vert[i*3+1] << ",\t" << vert[i*3+2] << endl;
	}

	xCount = divisions.x + 1;
	yCount = divisions.y + 1;
	cout << "cell count : " << xCount << "," << yCount << endl;
	i = 0;
	int c = 0;
	int cellCount = xCount * yCount;
	indices = new UnorderedList<unsigned int>(cellCount * 6 + 2);
	while (c < cellCount) {
		indices->Push(c);
		indices->Push(c + 1);
		indices->Push(c + xCount + 1);
		indices->Push(c + 1);
		indices->Push(c + xCount + 2);
		indices->Push(c + xCount + 1);
		cout << "[" << c << ".0]\t" << c << "," << c + 1 << "," << c + xCount + 1 << endl;
		cout << "[" << c << ".1]\t" << c + 1 << "," << c + xCount + 2 << "," << c + xCount + 1 << endl;
		ind[i++] = c;
		ind[i++] = c + 1;
		ind[i++] = c + xCount + 1;
		ind[i++] = c + 1;
		ind[i++] = c + xCount + 2;
		ind[i++] = c + xCount + 1;

		++c;
	}



	return true;
}


Mesh2D::Mesh2D() :
	parent(NULL),
	indices(new UnorderedList<unsigned int>),
	vertices(new UnorderedList<Double2>) {
	//ctr = 0;
}


Mesh2D::~Mesh2D(){
	cout << "DELETE MESH\n";
	if (!parent && vertices) {
		delete vertices;
	}
}
