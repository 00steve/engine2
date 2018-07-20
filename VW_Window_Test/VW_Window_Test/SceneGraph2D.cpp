#include "stdafx.h"
#include "SceneGraph2D.h"


void SceneGraph2D::Draw(Graphics *graphics){
	UnorderedList<Node*> drawables = ((Node*)graphics)->Children();
	//let the view do the dirty work of 
	int i = ((Node*)graphics)->Children().Count();
	while (i-- > 0) {
		Drawable *d = (Drawable*)drawables[i];
		d->Draw();
	}
}

SceneGraph2D::SceneGraph2D() {
	cout << "->SceneGraph2D";
}


SceneGraph2D::~SceneGraph2D() {
	cout << "->SceneGraph2D";
}

void SceneGraph2D::Update() {
}
