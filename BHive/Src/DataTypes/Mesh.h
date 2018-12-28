#ifndef MESH_H
#define MESH_H

#include "Core/Core.h"
#include "Texture2D.h"
#include "Shader.h"


namespace BHive
{
	struct BHIVE_API Vertex
	{
		glm::vec3 Position;
		glm::vec3 Color;
		glm::vec3 Normal;
		glm::vec2 TexCoord;
	};

	class BHIVE_API Mesh
	{
	public:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture2D> textures;

		Mesh(std::vector<Vertex> InVertices, std::vector<unsigned int> InIndices, std::vector<Texture2D> InTextures);
		void Draw(Shader* shader);

		unsigned int VAO;

	private:

		unsigned int VBO, EBO;

		void SetupMesh();
	};
}

#endif