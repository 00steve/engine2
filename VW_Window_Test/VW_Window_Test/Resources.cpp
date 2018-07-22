#include "stdafx.h"
#include "Resources.h"


bool Resources::Add(unsigned int type, string name, void * object)
{
	if (namedResources.Exists(name)) return false;
	Resource r;
	r.fileName = NULL;
	r.name = name;
	r.data = object;
	namedResources.Push(r,name);
	return true;
}

bool Resources::Load(unsigned int type, string fileName, string name)
{
	return false;
}

Resources::Resources()
{
}


Resources::~Resources()
{
}
