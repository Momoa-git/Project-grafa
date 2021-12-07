#pragma once
#include "Object.h"
#include "ObserverSkyBox.h"
//#include "ObserverDrawable.h"
#include "Shader.h"
#include <glm/glm.hpp>

class SkyBox : public ObserverSkyBox
{
private:
	Object sides[6];
	glm::vec3 position;
	bool initialised;

public:
	SkyBox(Shader* shader);
	void draw();
	virtual void update(glm::vec3 position) override;




};
