#pragma once
#include "Node.h"
#include "Drawable.h"
#include "Graphics.h"

class View : public Node{
private:
	Graphics * graphics;
protected:

public:

	virtual Node * AddChild(Node* newNode);

	virtual void Draw(Graphics* grpahics);

	void SetGraphics(Graphics* newGraphics);

	virtual void Update();

	View();
	~View();



};

