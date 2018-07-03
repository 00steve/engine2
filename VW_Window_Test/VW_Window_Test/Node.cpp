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

UnorderedList<Node*> Node::Children(){
	return children;
}


bool Node::MakeDestroyable() {
	if (references.Count() > 0) return false;
	return canDestroy = true;
}




Node::Node() {
	std::cout << "create [" << this << "]\n";
}


Node::~Node(){
	//if there are any references, remove them from the referencers, the 
	//things that are referencing this object
	std::cout << "delete [" << this << "]\n";
	while (references.Count()) {
		Node* referencesThis = references.Pop();
		std::cout << " - remove reference from [" << referencesThis << "]\n";
		referencesThis->RemoveReference(this);
	}

}

void Node::ReceiveMessage(Message* newMessage) {
	messages.Push(newMessage);
}

Node * Node::RemoveChild(Node * oldNode)
{
	return children.Cut(oldNode);
}

Node * Node::RemoveReference(Node * oldNode)
{
	return references.Cut(oldNode);
}

bool Node::SendMessage(Node * receiver, unsigned int id, void * data)
{
	Message* message = new Message();
	message->ID = id;
	message->Data = data;
	receiver->ReceiveMessage(message);
	return false;
}

bool Node::ProcessMessage(Message* message)
{
	switch (message->ID) {
	case MESSAGE_DEREFERENCE:
		return RemoveReference((Node*)message->Data);
	}
	return false;
}

bool Node::ProcessMessages()
{
	unsigned int i = messages.Count();
	while (i-- > 0) {
		ProcessMessage(messages[i]);
	}
	return false;
}

Node * Node::SetParent(Node * newNode)
{
	if (parent) RemoveReference(parent);
	AddReference(newNode);
	return parent = newNode;
}


void Node::Update() {
	ProcessMessages();

}