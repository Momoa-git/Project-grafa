#include "VAO.h"

VAO::VAO()
{
	id = 0;
	glGenVertexArrays(1, &id); //generate the VAO
}
//stdie nastavim na delku line
//offset o kolik je posunutý strideww
//layout - ukladam na konkretni index - to co menim porad, pointsLen - soucet vsech prvku v poli, 
void VAO::setAttribute(VBO& VBO, GLuint layout, int pointsLen, GLenum dataType, GLsizeiptr stride, void* offset)
{
	VBO.BindBuffer();
	glVertexAttribPointer(layout, pointsLen, dataType, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.ResetBindBuffer();

}

void VAO::BindBuffer()
{
	glBindVertexArray(id);
}

void VAO::ResetBindBuffer()
{
	glBindVertexArray(0);

}