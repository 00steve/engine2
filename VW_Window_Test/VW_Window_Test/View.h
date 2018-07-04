#pragma once
#include "Node.h"
#include "Drawable.h"

class View : public Drawable{
private:

protected:

public:

	virtual Node * AddChild(Node* newNode);

	void Draw();

	virtual void Update();

	View();
	~View();



};

