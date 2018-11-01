#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <string>

#include "Camera.h"
#include "ManagerGeometry.h"

class ApplicationOpenGl
{
public:
	void exec();

private:
	void openGlInit();

	void createWindows();
	void createViewport();
	void setupCallbackFunctions();
	void workCycle();
	
	int width = 1024;
	int height = 768;

	std::string title = "3D figures";
	GLFWwindow *window = nullptr;
	
	Camera camera;

	ManagerGeometry managerGeometry;

	glm::vec3 backgroundColor = glm::vec3(1.0f);
};

