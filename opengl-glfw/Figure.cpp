#include "Figure.h"
#include <GL/glew.h>


void Figure::vertexBinding()
{
	if (vertices.empty() || color.empty())
	{
		throw "Geometry not init";
	}

	GLuint colorBuffer, vertexBuffer;

	glGenBuffers(1, &colorBuffer);
	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBuffer);

	glBindVertexArray(vertexArrayObject);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * color.size(), color.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);


	glBindVertexArray(0);

	glDeleteBuffers(1, &colorBuffer);
	glDeleteBuffers(1, &vertexBuffer);
}

void Figure::draw()
{
	if (vertices.empty()) return;

	applyUniformParameters();

	drawGeometry();
}

void Figure::applyUniformParameters()
{
	if (!shader.isSuccess()) return;

	shader.use();

	GLint modelLoc = glGetUniformLocation(shader.getProgram(), "model");
	GLint viewLoc = glGetUniformLocation(shader.getProgram(), "view");
	GLint projLoc = glGetUniformLocation(shader.getProgram(), "projection");


	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}

void Figure::drawGeometry()
{
	drawTrianglesArrays(
		static_cast<int>(vertices.size() / 3)
	);
}

void Figure::drawTrianglesArrays(int trianglesCount, GLenum mode) const
{
	glBindVertexArray(vertexArrayObject);
	glDrawArrays(mode, 0, trianglesCount);
	glBindVertexArray(0);
}


void Figure::cleanUp()
{
	if (vertexArrayObject != 0)
	{
		glDeleteVertexArrays(1, &vertexArrayObject);
	}

	vertices.clear();
	color.clear();
}

void Figure::changeView(const glm::mat4 & v)
{
	view = v;
}

void Figure::changeProjection(const glm::mat4 & p)
{
	projection = p;
}

void Figure::scale(float scale)
{
	model = glm::scale(model, glm::vec3(scale));
}

void Figure::position(const glm::vec3 & position)
{
	model = glm::translate(model, position);
}

void Figure::rotate(float degree, const glm::vec3 &axis)
{
	model = glm::rotate(model, degree, axis);
}