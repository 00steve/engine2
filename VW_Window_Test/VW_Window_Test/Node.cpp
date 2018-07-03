#include "stdafx.h"
#include "Node.h"


Node * Node::AddChild(Node * newNode) {
	newNode->SetParent(this);
	AddReference(newNode);
	return children.Push(newNode);
}

Node * Node::AddReference(Node * newNode)
{
	canDestroy = false;
	return references.Push(newNode);
}

bool Node::CanDestroy() {
	return canDestroy;
}

bool Node::MakeDestroyable() {
	if (references.Count() > 0) return false;
	return canDestroy = true;
}




Node::Node() {

}


Node::~Node(){
}

Node * Node::RemoveReference(Node * oldNode)
{
	return references.Cut(oldNode);
}

Node * Node::SetParent(Node * newNode)
{
	if (parent) RemoveReference(parent);
	AddReference(newNode);
	return parent = newNode;
}


void Node::Update() {

}