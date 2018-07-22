#include "stdafx.h"
#include "Drawable.h"




void Drawable::Draw() {

}


GLenum Drawable::drawMode = GL_LINE_LOOP;


Drawable::Drawable() {
	cout << "->Drawable";
}


Drawable::~Drawable(){
}

GLenum Drawable::DrawMode(){
	return drawMode;
}

void Drawable::Update() {
	Node::Update();
}
