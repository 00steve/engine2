#include "stdafx.h"
#include "SceneGraph2D.h"


void SceneGraph2D::Draw(Graphics *graphics){

	//let the view do the dirty work of 


	//View::Draw();
	//figure out what drawables don't need to be drawn


	//draw the shit that should be on screen
	//glPushMatrix();
	////glTranslated(0, 0, -3);

	////glULookAt(0, 0, -10, 0, 0, 0, 1, 0);

	//glBegin(GL_LINES);
	//	glColor3d(1, 1, 1);
	//	glVertex3d(-1, 0, 0);
	//	glVertex3d(1, 0, 0);
	//glEnd();

	//glPopMatrix();
}

SceneGraph2D::SceneGraph2D() {
	cout << "->SceneGraph2D";
}


SceneGraph2D::~SceneGraph2D() {
	cout << "->SceneGraph2D";
}

void SceneGraph2D::Update() {
}
