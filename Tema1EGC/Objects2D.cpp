#include "Objects2D.h"

#include <Core/Engine.h>
#include <cmath>

Mesh* Objects2D::CreateShuriken(std::string name, glm::vec3 center, float length, glm::vec3 color)
{
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(0, -length, 0), color),
		VertexFormat(center + glm::vec3(length, -length, 0), color),
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(length, 0, 0), color),
		VertexFormat(center + glm::vec3(length, length, 0), color),
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(0, length, 0), color),
		VertexFormat(center + glm::vec3(-length, length, 0), color),
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(-length, 0, 0), color),
		VertexFormat(center + glm::vec3(-length, -length, 0), color),
		VertexFormat(center, color)
	};

	Mesh* shuriken = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	
	shuriken->SetDrawMode(GL_TRIANGLE_FAN);

	shuriken->InitFromData(vertices, indices);
	return shuriken;
}

Mesh* Objects2D::CreateArrow(std::string name, glm::vec3 leftcorner, float length, glm::vec3 color)
{
	glm::vec3 corner = leftcorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(0, length / 5, 0), color),
		VertexFormat(corner + glm::vec3(5 * length, length / 5, 0), color),
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(5 * length, 0, 0), color),
		VertexFormat(corner + glm::vec3(5 * length, length / 5, 0), color),
		VertexFormat(corner + glm::vec3(5 * length, length / 5, 0), color),
		VertexFormat(corner + glm::vec3(5 * length, length * 0.6, 0), color),
		VertexFormat(corner + glm::vec3(6 * length, length / 10, 0), color),
		VertexFormat(corner + glm::vec3(5 * length, length / 5, 0), color),
		VertexFormat(corner + glm::vec3(5 * length, - (length * 0.4), 0), color),
		VertexFormat(corner + glm::vec3(6 * length, length / 10, 0), color),
		VertexFormat(corner + glm::vec3(5 * length, length / 5, 0), color)
	};

	Mesh* arrow = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	arrow->SetDrawMode(GL_TRIANGLES);

	arrow->InitFromData(vertices, indices);
	return arrow;
}

Mesh* Objects2D::CreateBalloon(std::string name, glm::vec3 center, float radius, glm::vec3 color)
{
	int i;
	int triangleAmount = 20;

	float twicePi = 2 * M_PI;

	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;

	for (i = 0; i <= 20 ; i++) {
		vertices.push_back(VertexFormat(center + glm::vec3(radius * cos(i *  twicePi / triangleAmount), 
										radius * sin(i * twicePi / triangleAmount) * 1.5, 0), color));
		indices.push_back(i);
	}

	Mesh* balloon = new Mesh(name);

	balloon->SetDrawMode(GL_TRIANGLE_FAN);

	balloon->InitFromData(vertices, indices);
	return balloon;
}

Mesh* Objects2D::CreatePoliline(std::string name, glm::vec3 upcorner, glm::vec3 color)
{
	glm::vec3 corner = upcorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner - glm::vec3(-9, -9, 0), color),
		VertexFormat(corner - glm::vec3(0, -18, 0), color),
		VertexFormat(corner - glm::vec3(-9, -27, 0), color),
		VertexFormat(corner - glm::vec3(0, -36, 0), color)
	};

	Mesh* poliline = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3, 4 };

	poliline->SetDrawMode(GL_LINE_STRIP);

	poliline->InitFromData(vertices, indices);
	return poliline;
}

Mesh* Objects2D::CreateBow(std::string name, glm::vec3 center, float radius, glm::vec3 color)
{
	int i;
	int triangleAmount = 20;

	float twicePi = 2 * M_PI;

	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;

	for (i = 0; i <= 5; i++) {
		vertices.push_back(VertexFormat(center + glm::vec3(radius * cos(i *  twicePi / triangleAmount),
			radius * sin(i * twicePi / triangleAmount) * 1.5, 0), color));
		indices.push_back(i);
	}

	for (i = 15; i <= 20; i++) {
		vertices.push_back(VertexFormat(center + glm::vec3(radius * cos(i *  twicePi / triangleAmount),
			radius * sin(i * twicePi / triangleAmount) * 1.5, 0), color));
		indices.push_back(i - 9);
	}

	Mesh* bow = new Mesh(name);

	bow->SetDrawMode(GL_LINE_STRIP);

	bow->InitFromData(vertices, indices);
	return bow;
}

Mesh* Objects2D::CreatePowerBar(std::string name, glm::vec3 leftcorner, float length, glm::vec3 color)
{
	glm::vec3 corner = leftcorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(0, length, 0), color),
		VertexFormat(corner + glm::vec3(2 * length, length, 0), color),
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(2 * length, 0, 0), color),
		VertexFormat(corner + glm::vec3(2 * length, length, 0), color),
		VertexFormat(corner, color)
	};

	Mesh* powerbar = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3, 4, 5, 6 };

	powerbar->SetDrawMode(GL_TRIANGLES);

	powerbar->InitFromData(vertices, indices);
	return powerbar;
}