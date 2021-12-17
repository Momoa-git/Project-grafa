#include "FactoryObject.h"

FactoryObject::FactoryObject()
{
	
}

Object* FactoryObject::newObject(Model* model, Shader* shader)
{

	Object* object = new Object(model, shader);

	return object;

}

Object* FactoryObject::newObjectWithID(Model* model, Shader* shader, GLint objectID)
{
	
	Object* object = new Object(model, shader, objectID);

	return object;

}
