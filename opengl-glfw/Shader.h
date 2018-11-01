#pragma once
#include <string>

class Shader
{
public:
	void setShaderFile(const std::string &vertexPath, const std::string & fragmentPath);

	void use() const;

	unsigned getProgram() const;

	bool isSuccess() const;

private:
	unsigned program;
	int success;
};

