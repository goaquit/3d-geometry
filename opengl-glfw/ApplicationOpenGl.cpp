#include "ApplicationOpenGl.h"
#include "SynchronizationFrameSingleton.h"
#include "callbackFunctions.h"

#include <iostream>

void ApplicationOpenGl::exec()
{
	try
	{
		openGlInit();

		setupCallbackFunctions();

		managerGeometry.createFigure();
		managerGeometry.changePerspective(width, height);

		workCycle();

	}
	catch (const std::runtime_error &error)
	{
		std::cout << error.what() << std::endl;
	}	

	glfwTerminate();
}

void ApplicationOpenGl::openGlInit()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	createWindows();

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("Failed to initialize GLEW");
	}

	createViewport();

	glEnable(GL_DEPTH_TEST);
}

void ApplicationOpenGl::createWindows()
{
	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!window)
	{
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(window);
}

void ApplicationOpenGl::createViewport()
{
	int frameWidth, frameHeight;
	glfwGetFramebufferSize(window, &frameWidth, &frameHeight);

	glViewport(0, 0, frameWidth, frameHeight);
}

void ApplicationOpenGl::setupCallbackFunctions()
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetWindowUserPointer(window, &camera);
	glfwSetKeyCallback(window,callbackKey);
	glfwSetCursorPosCallback(window, callbackMouse);
}

void ApplicationOpenGl::workCycle()
{
	while (!glfwWindowShouldClose(window))
	{
		SynchronizationFrameSingleton::Instance().updateDelta(glfwGetTime());

		glfwPollEvents();

		camera.moving();

		glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		managerGeometry.draw(camera.viewMatrix());

		glfwSwapBuffers(window);
	}

	managerGeometry.clear();
}