#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Objects2D
{

	Mesh* CreateShuriken(std::string name, glm::vec3 center, float length, glm::vec3 color);

	Mesh* CreateArrow(std::string name, glm::vec3 leftcorner, float length, glm::vec3 color);

	Mesh* CreateBalloon(std::string name, glm::vec3 center, float radius, glm::vec3 color);

	Mesh* CreatePoliline(std::string name, glm::vec3 upcorner, glm::vec3 color);

	Mesh* CreateBow(std::string name, glm::vec3 center, float radius, glm::vec3 color);

	Mesh* CreatePowerBar(std::string name, glm::vec3 leftcorner, float length, glm::vec3 color);
}

