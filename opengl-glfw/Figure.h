#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

#include <vector>

class Figure
{
public:
	virtual ~Figure() {};

	virtual void init() = 0;
	virtual void vertexBinding();
	virtual void draw();
	virtual void cleanUp();
	virtual void drawGeometry();

	virtual void changeView(const glm::mat4 & v);
	virtual void changeProjection(const glm::mat4 & p);
	virtual void scale(float scale);
	virtual void position(const glm::vec3 &position);
	virtual void rotate(float degree, const glm::vec3 &axis);

protected:
	void applyUniformParameters();
	void drawTrianglesArrays(int trianglesCount, GLenum mode = GL_TRIANGLES) const;
	virtual void initPoints() = 0;

	Shader shader;
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	unsigned int vertexArrayObject;

	std::vector<float> vertices;
	std::vector<float> color;
};

