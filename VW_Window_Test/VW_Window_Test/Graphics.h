#pragma once
#include "Node.h"
#include "Drawable.h"

class Graphics : public Node{
private:

protected:

public:

	virtual Node * AddChild(Node* newNode);


	Graphics();
	~Graphics();

};

