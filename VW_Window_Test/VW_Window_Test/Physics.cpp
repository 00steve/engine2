#include "stdafx.h"
#include "Physics.h"


/*only add a child to the physics object if it is a physical object, meaning 
that it can be cast as a valid Physical*/
Node * Physics::AddChild(Node * newNode) {
	Physical* derived = dynamic_cast<Physical*>(newNode);
	if (derived) std::cout << " - added physical object [" << newNode << "]\n";
	return derived ? Node::AddChild(derived) : NULL;
}

void Physics::Draw(){
	cout << "draw physics";
}

Physics::Physics(){
	cout << "->Physics";
}


Physics::~Physics(){
	cout << "->Physics";
}


void Physics::Update() {

	Node::Update();
}