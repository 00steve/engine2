#pragma once

#include "Node.h"
#include "AABB.h"

class Physical : public Node{
private:
	bool isStatic;

protected:


public:
	Physical();
	~Physical();
};

