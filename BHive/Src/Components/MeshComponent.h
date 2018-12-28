#ifndef MESHCOMPONENT_H
#define MESHCOMPONENT_H


#include "Shader.h"
#include "Mesh.h"
#include <ASSIMP/Importer.hpp>
#include <ASSIMP/Scene.h>
#include <ASSIMP/postprocess.h>
#include "GameObjects/Camera.h"
#include "GameObjects/GameObject.h"

namespace BHive
{
	class MeshComponent;
	class BBox;

	class BHIVE_API BBox
	{
	public:

		BBox(std::vector<glm::vec3> InPositions, glm::vec3 InColor = glm::vec3(1.0f, .5f, 0.0f))
			:color(InColor)
		{
			CalculateBounds(InPositions);
		}

		BBox(glm::vec3 InMin, glm::vec3 InMax, glm::vec3 InColor = glm::vec3(1.0f, .5f, 0.0f))
			:color(InColor)
		{
			min = InMin;
			max = InMax;
		}

		~BBox()
		{
			delete shader;
		}

		glm::vec3 min;
		glm::vec3 max;
		glm::vec3 color;

		void CreateDrawBounds();

		void DrawBounds(MeshComponent* meshComponent);

	protected:
		void CalculateBounds(const std::vector<glm::vec3> positions);

	private:
		unsigned int VAO, EBO;
		unsigned int VBO;

		std::vector<unsigned int> indices;

		Shader* shader;
	};

	class BHIVE_API MeshComponent : public GameObject
	{
	public:

		MeshComponent(std::string path);

		void Draw(Shader* shader);
		void DrawBounds();

		BBox* BoundingBox;
		std::vector<BBox*> SubBoundingBoxes;

	private:

		std::vector<Texture2D> textures_loaded;

		std::vector<Mesh> meshes;
		std::string directory;
		bool gammaCorrection;

		void LoadMeshComponent(std::string path);
		void ProcessNode(aiNode * node, const aiScene* World);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* World);
		std::vector<Texture2D> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, ETextureType typeName);
		BBox* GetSubBoundingBox(int index);
	};
}

#endif // MeshComponent_H
