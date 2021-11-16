#include "ShaderLoader.h"

ShaderLoader::ShaderLoader(const char* vertexFileName, const char* fragmentFileName, GLuint* shaderID)
{
	*shaderID = loadShader(vertexFileName, fragmentFileName);

}
ShaderLoader::ShaderLoader()
{

}
ShaderLoader::~ShaderLoader()
{

}
string ShaderLoader::openFile(const char* name)
{
	ifstream file(name);
	if (!file.is_open())
	{
		cout << "Unable to open file " << name << endl;
		
	}
	std::stringstream fileData;
	fileData << file.rdbuf();
	file.close();
	return fileData.str();


}
GLuint ShaderLoader::loadShader(const char* vertexFileName, const char* fragmentFileName)
{
	printf("Shader::loadShader %s %s \n", vertexFileName, fragmentFileName);
	string vertexShaderString = openFile(vertexFileName);
	string fragmentShaderString = openFile(fragmentFileName);
	int vlen = vertexShaderString.length();
	int flen = fragmentShaderString.length();

	if (vertexShaderString.empty()) 
		printf("Empty Vertex Shader\n");
	if (fragmentShaderString.empty())
		printf("Empty Fragment Shader\n");

	const char* vertexShaderCStr = vertexShaderString.c_str();
	const char* fragmentShaderCStr = fragmentShaderString.c_str();

	//create and compile shaders
	vertexID = glCreateShader(GL_VERTEX_SHADER);    //Vertex Shader
	glShaderSource(vertexID, 1, (const GLchar * *)& vertexShaderCStr, &vlen);
	glCompileShader(vertexID);
	GLint status;
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(vertexID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compile failure in Vertex shader:\n%s\n", strInfoLog);
		delete[] strInfoLog;
	}

	fragmentID = glCreateShader(GL_FRAGMENT_SHADER); //Fragment Shader
	glShaderSource(fragmentID, 1, (const GLchar * *)& fragmentShaderCStr, &flen);
	glCompileShader(fragmentID);

	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(fragmentID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compile failure in Fragment shader:\n%s\n", strInfoLog);
		delete[] strInfoLog;
	}

	shaderProgramID = glCreateProgram();
	glAttachShader(shaderProgramID, vertexID);
	glAttachShader(shaderProgramID, fragmentID);
	glLinkProgram(shaderProgramID);

	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgramID, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgramID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
	else printf(" Shader:Load OK \n");

	return shaderProgramID;





}
