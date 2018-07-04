#include "stdafx.h"
#include "View.h"


Node * View::AddChild(Node * newNode) {
	return newNode;
}

void View::Draw(){
	//set the viewport extents (as far as x/y pixels go in the monitor)
	//translate the view based on the "camera"

}

void View::Update() {
	Drawable::Update();
}

View::View() {
}


View::~View() {
}
