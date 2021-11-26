#pragma once
#include "PointLight.h"
#include "LightBase.h"
#include "LightAttenuation.h"
class SpotLight : public LightBase, public LightAttenuation
{
public:
	glm::vec3 position;
	glm::vec3 direction;
	float cutOff;
	float outerCutOff;
	
	SpotLight(glm::vec3 direction, glm::vec3 position);
	SpotLight(glm::vec3 direction, float cutOff, float outerCutOff, glm::vec3 position);
	

	void setPositionUni(GLint location);
	void setDirection(glm::vec3 direction);
	void setCutOffUni(GLint location);
	void setOuterCutOffUni(GLint location);
	void setDirectionUni(GLint location);

	
};
