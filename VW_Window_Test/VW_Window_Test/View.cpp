#include "stdafx.h"
#include "View.h"


Node * View::AddChild(Node * newNode) {
	return newNode;
}

void View::Draw(Graphics* grpahics) {
	//set the viewport extents (as far as x/y pixels go in the monitor)
	//translate the view based on the "camera"
	//render each of the graphics on the screen if it makes sense to
}

void View::SetGraphics(Graphics * newGraphics) {
	graphics = newGraphics;
}

void View::Update() {
}

View::View() {
}


View::~View() {
}
