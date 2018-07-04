#include "stdafx.h"
#include "SceneGraph2D.h"


void SceneGraph2D::Draw(){
	//let the view do the dirty work of 
	View::Draw();
	//figure out what drawables don't need to be drawn

	//draw the shit that should be on screen

}

SceneGraph2D::SceneGraph2D(){
	cout << "->SceneGraph2D";
}


SceneGraph2D::~SceneGraph2D()
{
}

void SceneGraph2D::Update() {
	cout << "u";
}
