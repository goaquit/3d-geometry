#include "Camera.h"
#include "SynchronizationFrameSingleton.h"

glm::mat4 Camera::viewMatrix()
{
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::setSize(int width, int height)
{
	lastX = width / 2.0;
	lastY = height / 2.0;
}

void Camera::moving()
{
	GLfloat cameraSpeed = 5.0f * static_cast<GLfloat>(
		SynchronizationFrameSingleton::Instance().deltaTime()
		);

	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
		cameraPos += cameraSpeed * cameraFront;
	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
		cameraPos -= cameraSpeed * cameraFront;
	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void Camera::mouseMoving(double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	const auto xoffset = xpos - lastX;
	const auto yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	yaw += static_cast<float>(xoffset * sensitivity);
	pitch += static_cast<float>(yoffset * sensitivity);

	const auto maxPitch = 89.0f;
	if (pitch > maxPitch)
		pitch = maxPitch;
	if (pitch < -maxPitch)
		pitch = -maxPitch;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
}

void Camera::keyProcessing(int key, int scancode, int action, int mode)
{
	if (action == GLFW_PRESS)
		keys[key] = true;
	else if (action == GLFW_RELEASE)
		keys[key] = false;
}