#include "Tema1.h"

#include <vector>
#include <iostream>
#include <cmath>

#include <Core/Engine.h>
#include "Transforms2D.h"
#include "Objects2D.h"

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	
	// initialize tx and ty (the translation steps)
	tXarrow = 50;
	tYarrow = 350;
	tYarc = 350;
	tXshuriken1 = 1800;
	tXshuriken2 = 1800;
	tXshuriken3 = 1800;
	tYballoon1 = 0;
	tYballoon2 = 0;
	tYballoon3 = 0;
	tYballoon4 = 0;

	// initialize sx and sy (the scale factors)
	scaleX = 1;
	scaleY = 1;
	
	// initialize angularStep
	angularStep1 = 0;
	angularStep2 = 0;
	angularStep3 = 0;

	sh = false;
	sh2 = false;
	bal = false;
	bal2 = false;
	bal3 = false;
	mousepressed = false;
	standingarrow = true;
	

	Mesh* arrow = Objects2D::CreateArrow("arrow", corner, 20, glm::vec3(1, 0, 0));
	AddMeshToList(arrow);
	
	Mesh* shuriken = Objects2D::CreateShuriken("shuriken", corner, 30, glm::vec3(0.627, 0.627, 0.627));
	AddMeshToList(shuriken);

	Mesh* balloon_red = Objects2D::CreateBalloon("balloon_red", corner, 30, glm::vec3(1, 0, 0));
	AddMeshToList(balloon_red);

	Mesh* poliline_red = Objects2D::CreatePoliline("poliline_red", corner, glm::vec3(1, 0, 0));
	AddMeshToList(poliline_red);

	Mesh* balloon_yellow = Objects2D::CreateBalloon("balloon_yellow", corner, 30, glm::vec3(1, 1, 0));
	AddMeshToList(balloon_yellow);

	Mesh* poliline_yellow = Objects2D::CreatePoliline("poliline_yellow", corner, glm::vec3(1, 1, 0));
	AddMeshToList(poliline_yellow);

	Mesh* bow = Objects2D::CreateBow("bow", corner, 50, glm::vec3(0.6, 0.298, 0));
	AddMeshToList(bow);

	Mesh* powerbar = Objects2D::CreatePowerBar("powerbar", corner, 20, glm::vec3(0.54, 0.16, 0.88));
	AddMeshToList(powerbar);
}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transforms2D::Translate(50, tYarc);

	modelMatrix *= Transforms2D::Rotate(angularStep1 / 500);

	glLineWidth(5);

	RenderMesh2D(meshes["bow"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transforms2D::Translate(tXarrow, tYarrow);

	modelMatrix *= Transforms2D::Rotate(angularStep3 / 500);

	glLineWidth(5);

	RenderMesh2D(meshes["arrow"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);

	angularStep2 += deltaTimeSeconds * 0.5;
	tXshuriken1 -= deltaTimeSeconds * 200;
	modelMatrix *= Transforms2D::Translate(tXshuriken1, 200);
	modelMatrix *= Transforms2D::Rotate(4 * angularStep2);

	RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);

	if ((tXshuriken1 < 1000) && (!sh))
		sh = true;

	if (sh)
	{
		modelMatrix = glm::mat3(1);

		tXshuriken2 -= deltaTimeSeconds * 200;
		modelMatrix *= Transforms2D::Translate(tXshuriken2, 400);
		modelMatrix *= Transforms2D::Rotate(4 * angularStep2);

		RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);
	}

	if (tXshuriken1 < -50)
		tXshuriken1 = 1800;

	if (tXshuriken2 < -50)
	{
		tXshuriken2 = 1800;
		sh = false;
	}

	if ((tXshuriken2 < 1200) && (!sh2))
		sh2 = true;

	if (sh2)
	{
		modelMatrix = glm::mat3(1);

		tXshuriken3 -= deltaTimeSeconds * 200;
		modelMatrix *= Transforms2D::Translate(tXshuriken3, 600);
		modelMatrix *= Transforms2D::Rotate(4 * angularStep2);

		RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);
	}

	if (tXshuriken3 < -50)
	{
		tXshuriken3 = 1800;
		sh2 = false;
	}

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transforms2D::Translate(250, -300);

	tYballoon1 += deltaTimeSeconds * 100;

	modelMatrix *= Transforms2D::Translate(0, tYballoon1);

	RenderMesh2D(meshes["balloon_red"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transforms2D::Translate(242.5, -376);

	modelMatrix *= Transforms2D::Translate(0, tYballoon1);

	glLineWidth(3);

	RenderMesh2D(meshes["poliline_red"], shaders["VertexColor"], modelMatrix);

	if ((tYballoon1 > 500) && (!bal))
		bal = true;

	if (bal)
	{
		tYballoon2 += deltaTimeSeconds * 100;

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transforms2D::Translate(500, -300);;

		modelMatrix *= Transforms2D::Translate(0, tYballoon2);

		RenderMesh2D(meshes["balloon_yellow"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transforms2D::Translate(492.5, -376);

		modelMatrix *= Transforms2D::Translate(0, tYballoon2);

		glLineWidth(3);

		RenderMesh2D(meshes["poliline_yellow"], shaders["VertexColor"], modelMatrix);
	}

	if (tYballoon1 > 1200)
		tYballoon1 = 0;

	if (tYballoon2 > 1200)
	{
		tYballoon2 = 0;
		bal = false;
	}

	if ((tYballoon2 > 500) && (!bal2))
		bal2 = true;

	if (bal2)
	{
		tYballoon3 += deltaTimeSeconds * 100;

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transforms2D::Translate(750, -300);;

		modelMatrix *= Transforms2D::Translate(0, tYballoon3);

		RenderMesh2D(meshes["balloon_yellow"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transforms2D::Translate(742.5, -376);

		modelMatrix *= Transforms2D::Translate(0, tYballoon3);

		glLineWidth(3);

		RenderMesh2D(meshes["poliline_yellow"], shaders["VertexColor"], modelMatrix);
	}

	if (tYballoon3 > 1200)
	{
		tYballoon3 = 0;
		bal2 = false;
	}

	if ((tYballoon3 > 500) && (!bal3))
		bal3 = true;

	if (bal3)
	{
		tYballoon4 += deltaTimeSeconds * 100;

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transforms2D::Translate(1000, -300);;

		modelMatrix *= Transforms2D::Translate(0, tYballoon4);

		RenderMesh2D(meshes["balloon_red"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transforms2D::Translate(992.5, -376);

		modelMatrix *= Transforms2D::Translate(0, tYballoon4);

		glLineWidth(3);

		RenderMesh2D(meshes["poliline_red"], shaders["VertexColor"], modelMatrix);
	}

	if (tYballoon4 > 1200)
	{
		tYballoon4 = 0;
		bal3 = false;
	}

	if (mousepressed)
	{
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transforms2D::Translate(25, 25);

		modelMatrix *= Transforms2D::Scale(scaleX, 1);

		RenderMesh2D(meshes["powerbar"], shaders["VertexColor"], modelMatrix);
	}
}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	if ((tYarc <= 620) && (tYarc >= 100))
	{
		if (window->KeyHold(GLFW_KEY_W)) {
			tYarc += deltaTime * 200;

			if(standingarrow)
				tYarrow += deltaTime * 200;
		}

		if (window->KeyHold(GLFW_KEY_S)) {
			tYarc -= deltaTime * 200;

			if(standingarrow)
				tYarrow -= deltaTime * 200;
		}
	}
	else if (tYarc > 620)
		tYarc = 620;
	else if (tYarc < 100)
		tYarc = 100;

	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
	{
		if(scaleX < 6)
			scaleX += deltaTime * 10;

		mousepressed = true;
	}

	if (!window->MouseHold(GLFW_MOUSE_BUTTON_LEFT) && (mousepressed))
	{
		angularStep3 = angularStep1;
		standingarrow = false;
		mousepressed = false;
	}

	if (!standingarrow)
	{
		tXarrow += scaleX;
		tYarrow += scaleX * tan(angularStep3 / 500);
	}

	if ((tXarrow > 1800) || (tYarrow > 1000) || (tXarrow < 0))
	{
		standingarrow = true;
		tXarrow = 50;
		tYarrow = tYarc;
		scaleX = 1;
	}
}

void Tema1::OnKeyPress(int key, int mods)
{
	
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	angularStep1 = 350 - mouseY;
	
	if (standingarrow)
		angularStep3 = 350 - mouseY;
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
