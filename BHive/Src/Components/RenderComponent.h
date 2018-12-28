#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H


#include "Components/TransformComponent.h"
#include "Shader.h"

namespace BHive
{
	class BHIVE_API RenderComponent : public TransformComponent
	{
	public:
		RenderComponent();
		virtual ~RenderComponent();

		virtual void ComponentStart() override;
		virtual void ComponentUpdate(float deltaTime) override;
		virtual void Construct();
		virtual void Render();
		void SetShader(Shader* shader);

		unsigned int vao, vbo, ebo;

		std::vector<float> positions;
		std::vector<unsigned int> indices;
		std::string vertexShader, fragmentShader;

		Shader* shader;
	};
}

#endif // 