#include "Tema2.h"

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

#include <Core/Engine.h>

using namespace std;

Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

void Tema2::Init()
{
	// Create a simple cube
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 1, 1), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0, 1), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(0, 1, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 1, 1), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 1, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(0, 0, 1), glm::vec3(1, 0, 0)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh("redcube", vertices, indices);
	}

	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 1, 1), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0, 1), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0, 0), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(0, 1, 0), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 1, 1), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 1, 0), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(0, 0, 1), glm::vec3(1, 1, 0)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh("yellowcube", vertices, indices);
	}

	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 1, 1), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0, 1), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 1, 1), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 1, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh("greencube", vertices, indices);
	}

	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 1, 1), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0, 1), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 1, 1), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 1, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(0, 0, 1), glm::vec3(0, 0, 1)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh("bluecube", vertices, indices);
	}

	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 1, 1), glm::vec3(0.9, 0.5, 0.13)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0, 1), glm::vec3(0.9, 0.5, 0.13)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0, 0), glm::vec3(0.9, 0.5, 0.13)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(0, 1, 0), glm::vec3(0.9, 0.5, 0.13)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1), glm::vec3(0.9, 0.5, 0.13)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 1, 1), glm::vec3(0.9, 0.5, 0.13)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 1, 0), glm::vec3(0.9, 0.5, 0.13)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(0, 0, 1), glm::vec3(0.9, 0.5, 0.13)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh("orangecube", vertices, indices);
	}

	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1, 1), glm::vec3(0, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(1, -1, 1), glm::vec3(0, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(0, 1,  0), glm::vec3(0, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(0, 0, 0), glm::vec3(1, 0, 0)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		2, 1, 3,
			3, 4, 2,		2, 0, 4,
			4, 0, 3,		3, 1, 0,
		};

		CreateMesh("pyramid", vertices, indices);
	}

	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-0.5, -0.5, 2), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(0.5, -0.5, 2), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(0, 0.5,  2), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(-0.5, -0.5, -2), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(0.5, -0.5, -2), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(0, 0.5,  -2), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		2, 1, 4,
			4, 5, 2,		2, 0, 3,
			3, 5, 2,		3, 4, 5,
			0, 1, 3,        3, 4, 1,
		};

		CreateMesh("triangular_prism", vertices, indices);
	}

	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-0.3, -2, 0.3), glm::vec3(0, 1, 1), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(0.3, -2, 0.3), glm::vec3(1, 0, 1), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(-0.3, -2, -0.3), glm::vec3(1, 0, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(0.3, -2, -0.3), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(-0.3, 2, 0.3), glm::vec3(0, 1, 1), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(0.3, 2, 0.3), glm::vec3(1, 0, 1), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(-0.3, 2, -0.3), glm::vec3(1, 0, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(0.3, 2, -0.3), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,		1, 3, 2,
			2, 3, 7,		2, 7, 6,
			1, 7, 3,		1, 5, 7,
			6, 7, 4,		7, 5, 4,
			0, 4, 1,		1, 4, 5,
			2, 6, 4,		0, 2, 4,
		};

		CreateMesh("pillar", vertices, indices);
	}

	renderCameraTarget = false;

	camera = new Laborator::Camera();
	camera->Set(glm::vec3(0, 1.5, 3), glm::vec3(0, 1.5, 0), glm::vec3(0, 1.5, 0));
	z[0] = -1;
	z[1] = -9;
	z[2] = -17.5;
	z[3] = -2;
	z[4] = -9.5;
	z[5] = -17;
	z[6] = 0;
	z[7] = -6;
	z[8] = -12.5;
	z[9] = -18.5;
	x = 0;
	y = 0.6f;
	xfuel = -1.5f;
	xfuel2 = -1.5f;
	yfuel = 3;
	zfuel = 0;
	xscale = 1;
	sph1scale = 0.4f;
	sph2scale = 0.4f;
	jumping = false;

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
}

Mesh* Tema2::CreateMesh(const char *name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned short> &indices)
{
	unsigned int VAO = 0;
	// TODO: Create the VAO and bind it
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// TODO: Create the VBO and bind it
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// TODO: Send vertices data into the VBO buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// TODO: Crete the IBO and bind it
	unsigned int IBO;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	// TODO: Send indices data into the IBO buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// ========================================================================
	// This section describes how the GPU Shader Vertex Shader program receives data

	// set vertex position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	// set vertex normal attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// set texture coordinate attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// set vertex color attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
	// ========================================================================

	// Unbind the VAO
	glBindVertexArray(0);

	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object
	meshes[name] = new Mesh(name);
	meshes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	meshes[name]->vertices = vertices;
	meshes[name]->indices = indices;
	return meshes[name];
}

void Tema2::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::Update(float deltaTimeSeconds)
{
	for (int i = 0; i < 10; i++)
		z[i] += deltaTimeSeconds * 2;

	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, z[0]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.1f, 2.5f));
	RenderMesh(meshes["bluecube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-5, 1, z[0]));
	RenderMesh(meshes["triangular_prism"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0.6f, z[0]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.5f, 0.5f));
	RenderMesh(meshes["redcube"], shaders["VertexNormal"], modelMatrix);

	if (z[0] > 4)
		z[0] = z[2] - 7.5f;

	if (IntersectSphereCube(-3, z[0]))
		exit(0);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, z[1]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.1f, 3.5f));
	RenderMesh(meshes["yellowcube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-5, 1, z[1]));
	RenderMesh(meshes["pillar"], shaders["VertexNormal"], modelMatrix);

	if (z[1] > 5)
		z[1] = z[0] - 8;

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, z[2]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.1f, 3));
	RenderMesh(meshes["bluecube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-6, 1, z[2]));
	RenderMesh(meshes["pyramid"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 1, z[2]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(sph1scale));
	RenderMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix);
	if (z[2] > 4.5f) {
		z[2] = z[1] - 8.5f;
		sph1scale = 0.4f;
	}

	if (IntersectSphereSphere(-3, 1, z[2])) {
		xscale += 0.005f;
		xfuel += 0.005f;
		sph1scale = 0;
	}

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0, z[3]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75, 0.1f, 3.5f));
	RenderMesh(meshes["orangecube"], shaders["VertexNormal"], modelMatrix);
	if (z[3] > 5)
		z[3] = z[5] - 9;

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0, z[4]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.1f, 2));
	RenderMesh(meshes["bluecube"], shaders["VertexNormal"], modelMatrix);
	if (z[4] > 3.5f)
		z[4] = z[3] - 7.5f;

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0, z[5]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.1f, 3.5f));
	RenderMesh(meshes["yellowcube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.6f, z[5]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.5f, 0.5f));
	RenderMesh(meshes["redcube"], shaders["VertexNormal"], modelMatrix);
	if (z[5] > 5)
		z[5] = z[4] - 7.5f;

	if (IntersectSphereCube(0, z[5]))
		exit(0);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(3, 0, z[6]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75, 0.1f, 1.5f));
	RenderMesh(meshes["greencube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(6, 1, z[6]));
	RenderMesh(meshes["pyramid"], shaders["VertexNormal"], modelMatrix);

	if (z[6] > 3)
		z[6] = z[9] - 5.5f;

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(3, 0, z[7]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.1f, 2.5f));
	RenderMesh(meshes["redcube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(5, 1, z[7]));
	RenderMesh(meshes["triangular_prism"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(3, 1, z[7]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(sph2scale));
	RenderMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix);

	if (z[7] > 4) {
		z[7] = z[6] - 6;
		sph2scale = 0.4f;
	}

	if (IntersectSphereSphere(3, 1, z[7])) {
		xscale += 0.005f;
		xfuel += 0.005f;
		sph2scale = 0;
	}

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(3, 0, z[8]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.1f, 2));
	RenderMesh(meshes["orangecube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(5, 1, z[8]));
	RenderMesh(meshes["pillar"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(3, 0.6f, z[8]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.5f, 0.5f));
	RenderMesh(meshes["redcube"], shaders["VertexNormal"], modelMatrix);

	if (z[8] > 3.5f)
		z[8] = z[7] - 6.5f;

	if (IntersectSphereCube(3, z[8]))
		exit(0);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(3, 0, z[9]));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f, 0.1f, 2));
	RenderMesh(meshes["bluecube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(6, 1, z[9]));
	RenderMesh(meshes["pyramid"], shaders["VertexNormal"], modelMatrix);

	if (z[9] > 3.5f)
		z[9] = z[8] - 6;

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, 0));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(1));
	RenderMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(xfuel2, yfuel, zfuel));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 0.1f, 0.01f));
	RenderMesh(meshes["yellowcube"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(xfuel + 0.065f, yfuel - 0.05f, zfuel + 0.1f));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(xscale, 0.1f, 0.01f));
	RenderMesh(meshes["redcube"], shaders["VertexNormal"], modelMatrix);

	if (jumping) {
		if (y < 2) {
			y += deltaTimeSeconds * 2;
			if (renderCameraTarget) {
				camera->TranslateUpword(deltaTimeSeconds * 2);
				yfuel += deltaTimeSeconds * 2;
			}
		}
		else
			jumping = false;
	}

	if ((y > 0.6f) && (!jumping)) {
		y -= deltaTimeSeconds * 2;
		if (renderCameraTarget) {
			camera->TranslateUpword(-deltaTimeSeconds * 2);
			yfuel -= deltaTimeSeconds * 2;
		}
	}

	if ((x < -4) || ((x > -2) && (x < -1)) || ((x > 1) && (x < 2)) || (x > 4))
		if (!jumping) {
			y -= deltaTimeSeconds * 2;
			if (renderCameraTarget) {
				camera->TranslateUpword(-deltaTimeSeconds * 2);
			}
		}

	if (y < -7)
		exit(0);

	xfuel -= deltaTimeSeconds / 20;
	xscale -= deltaTimeSeconds / 20;

	if (xscale < 0)
		exit(0);
}

void Tema2::FrameEnd()
{
	//DrawCoordinatSystem(camera->GetViewMatrix(), projectionMatrix);
}

void Tema2::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
{
	if (!mesh || !shader || !shader->program)
		return;

	// render an object using the specified shader and the specified position
	shader->Use();
	glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
	glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	mesh->Render();
}

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_W)) {
		for (int i = 0; i < 10; i++)
			z[i] += deltaTime * 2;
		xfuel -= deltaTime / 40;
		xscale -= deltaTime / 40;
	}

	if (window->KeyHold(GLFW_KEY_S)) {
		for (int i = 0; i < 10; i++)
			z[i] -= deltaTime;
		xfuel += deltaTime / 40;
		xscale += deltaTime / 40;
	}

	if (window->KeyHold(GLFW_KEY_A)) {
		x -= deltaTime * 2;
		camera->TranslateRight(-deltaTime * 2);
		xfuel -= deltaTime * 2;
		xfuel2 -= deltaTime * 2;
	}

	if (window->KeyHold(GLFW_KEY_D)) {
		x += deltaTime * 2;
		camera->TranslateRight(deltaTime * 2);
		xfuel += deltaTime * 2;
		xfuel2 += deltaTime * 2;
	}
}

void Tema2::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_SPACE && y <= 0.6f && y > 0) {
		jumping = true;
	}

	if (key == GLFW_KEY_C && y <= 0.6f && y > 0) {
		if (renderCameraTarget == false) {
			renderCameraTarget = true;
			camera->MoveForward(3);
			zfuel -= 3;
		}
		else {
			renderCameraTarget = false;
			camera->MoveForward(-3);
			zfuel += 3;
		}
	}
}

bool Tema2::IntersectSphereCube(float xc, float z) {

	
	float xi = max((xc - 0.75f), min(x, (xc + 1.2f)));
	float yi = max((0.6f - 0.5f), min(y, (0.6f + 0.5f)));
	float zi = max((z - 0.5f), min(0.f, (z + 0.2f)));

	float distance = sqrt((xi - x) * (xi - x) +
						  (yi - y) * (yi - y) +
						  (zi - 0) * (zi - 0));

	if (distance < 0.5f)
		return true;

	return false;
}

bool Tema2::IntersectSphereSphere(float xs, float ys, float zs) {
	float distance = sqrt((x - xs) * (x - xs) +
						  (y - ys) * (y - ys) +
						  (0 - zs) * (0 - zs));

	return distance < (0.5f + 0.2f);
}

void Tema2::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}
