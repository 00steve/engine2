#include "stdafx.h"
#include "Graphics.h"


Node * Graphics::AddChild(Node * newNode)
{
	Drawable* drawable = dynamic_cast<Drawable*>(newNode);
	if (drawable) std::cout << " - added drawable object [" << newNode << "]\n";
	return drawable ? Node::AddChild(drawable) : NULL;
}

Graphics::Graphics(){
	cout << "->Graphics";
}


Graphics::~Graphics(){

}
