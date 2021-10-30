#include "FactoryObject.h"

FactoryObject::FactoryObject()
{
	
}


Object* FactoryObject::newObject(Model* model, Shader* shader)
{
	
	Object* object = new Object(model, shader);

	return object;

}
