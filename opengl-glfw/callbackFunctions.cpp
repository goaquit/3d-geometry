#include "callbackFunctions.h"
#include "Camera.h"

void callbackMouse(GLFWwindow * window, double xpos, double ypos)
{
	Camera * camera = reinterpret_cast<Camera *>(glfwGetWindowUserPointer(window));

	camera->mouseMoving(xpos, ypos);
}

void callbackKey(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	Camera * camera = reinterpret_cast<Camera *>(glfwGetWindowUserPointer(window));

	camera->keyProcessing(key, scancode, action, mode);

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}