#pragma once
#include "Map.h"

#define RESOURCE_TEXTURE 1
#define RESOURCE_MESH 2
#define RESOURCE_MODEL_STATIC 3





struct Resource {
	string *fileName;
	string name;
	/*store an int that represents the type of object that is being stored,
	this could be used later to check if the object can be cast back into 
	that type, to tell if the data is valid*/
	unsigned int type;
	/*the data of the object. Based on the type, it should be able to be 
	re-cast back into whatever object it should be cast into.*/
	void* data;
};



class Resources {
private:
	/*keep two maps of the resources that are loaded, based on the filename and on
	what the resource is named during the loading. The name should be unique.*/
	Map<Resource> fileResources;
	Map<Resource> namedResources;
public:
	/*add an object of a certain type that has been created at runtime*/
	bool Add(unsigned int type, string name, void* object);

	/*add an object of a certain type that has been loaded from a file, 
	this will require having a way to parse the file into the objec type*/
	bool Load(unsigned int type, string fileName, string name);

	Resources();
	~Resources();
};

