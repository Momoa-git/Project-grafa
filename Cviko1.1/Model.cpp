#include "Model.h"
#include <vector>

Model::Model(GLboolean bit,const GLfloat* points, int size, int lineLen, int vecLen, int uniformCount, GLenum pointsType)
{
	
	this->texture = nullptr;
	point = size / lineLen;
	this->pointsType = pointsType;
	
	//layoutCOunt
	int top = 0;

	if (uniformCount == 0)
		top = lineLen / vecLen;
	else
		top = uniformCount;

	vbo = new VBO(points, size);
	vao = new VAO();
	vao->BindBuffer();
	for (int i = 0; i < top; i++) 
	{
		vao->setAttribute(*vbo, i, vecLen, GL_FLOAT, lineLen * sizeof(GL_FLOAT), (GLvoid*)(i * vecLen * sizeof(GL_FLOAT)));
	}
	vao->ResetBindBuffer();
	vbo->ResetBindBuffer();

}

Model::Model(const GLfloat* points, int pointNo, int lineLen) {
	this->texture = nullptr;
	this->point = pointNo;
	this->lineLen = lineLen;
	this->pointsType = GL_TRIANGLES;
	vbo = new VBO(points, pointNo * lineLen);
	vao = new VAO();
	vao->BindBuffer();
}

Model::Model(const char* modelData) {
	this->texture = nullptr;
	this->pointsType = GL_TRIANGLES;

	int count = 0;
	Assimp::Importer importer;
	unsigned int importOptions = aiProcess_Triangulate
		| aiProcess_OptimizeMeshes              // slouèení malých plošek
		| aiProcess_JoinIdenticalVertices       // NUTNÉ jinak hodnì duplikuje
		| aiProcess_Triangulate                 // prevod vsech ploch na trojuhelniky
		| aiProcess_CalcTangentSpace;           // vypocet tangenty, nutny pro spravne pouziti normalove mapy
	const aiScene* scene = importer.ReadFile(modelData, importOptions);
	vector<float> data;
	if (scene) {
		aiMesh* mesh = scene->mMeshes[0];
		count = mesh->mNumFaces * 3;
		for (unsigned int i = 0; i < mesh->mNumFaces; i++) 
		{
			for (unsigned int j = 0; j < 3; j++)
			{
				data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].x);
				data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].y);
				data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].z);
				data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].x);
				data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].y);
				data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].z);
				data.push_back(mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]].x);
				data.push_back(mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]].y);
			}
		}
	}
	vbo = new VBO(data);
	vao = new VAO();
	vao->BindBuffer();

	this->point = data.size() / 8;
	this->lineLen = 8;
}


VBO* Model::getVBO()
{
	return vbo;

}

VAO* Model::getVAO()
{
	return vao;

}

GLenum Model::getpointsType()
{
	return pointsType;
}

int Model::getPointsLen()
{
	return point;

}

void Model::setTexture(Texture* texture)
{
	this->texture = texture;
}

BuilderModel Model::create(const GLfloat* points, GLint pointNo, GLint lineLen) {
	return BuilderModel(points, pointNo, lineLen);
}

BuilderModel Model::create(const char* data)
{
	return BuilderModel(data);
}



