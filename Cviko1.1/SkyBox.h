#pragma once
#include "Object.h"
#include "ObserverSkyBox.h"
#include "ObserverDrawable.h"
#include "Shader.h"
#include <glm/glm.hpp>

class SkyBox : public ObserverSkyBox, public ObserverDrawable
{
private:
	Object sides[6];
	glm::vec3 position;
	bool initialised;

public:
	SkyBox(Shader* shader);
	virtual void draw() override;
	virtual void update(glm::vec3 position) override;




};
