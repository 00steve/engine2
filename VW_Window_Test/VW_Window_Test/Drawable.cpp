#include "stdafx.h"
#include "Drawable.h"


void Drawable::Draw() {

}


Drawable::Drawable() {
	cout << "->Drawable";
}


Drawable::~Drawable(){
}

void Drawable::Update() {
	Node::Update();
}
