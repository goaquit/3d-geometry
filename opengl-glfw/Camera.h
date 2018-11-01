#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	glm::mat4 viewMatrix();

	void setSize(int width, int height);

	void moving();

	void mouseMoving(double xpos, double ypos);

	void keyProcessing(int key, int scancode, int action, int mode);

private:
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	float yaw = -90.0f;
	float pitch = 0.0f;
	const double sensitivity = 0.05;

	bool firstMouse = true;

	double lastX = 0.0, lastY = 0.0;

	bool keys[1024];
};

