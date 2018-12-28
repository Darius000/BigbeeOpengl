#include "pch.h"
#include "RenderComponent.h"
#include "GameObjects/Camera.h"
#include "Core/Statics.h"

namespace BHive
{
	RenderComponent::RenderComponent()
		:shader(0)
	{

	}


	RenderComponent::~RenderComponent()
	{

	}


	void RenderComponent::ComponentStart()
	{
		TransformComponent::ComponentStart();

		if (!vertexShader.empty() && !fragmentShader.empty() && !shader)
		{
			shader = new Shader(vertexShader.c_str(), fragmentShader.c_str());
		}

		Construct();
	}

	void RenderComponent::ComponentUpdate(float deltaTime)
	{
		TransformComponent::ComponentUpdate(deltaTime);

		Render();
	}

	void RenderComponent::Construct()
	{

	}

	void RenderComponent::Render()
	{
		shader->Use();
		shader->SetMatrix4("PVM",
			Statics::GetActiveCamera()->GetProjectionMatrix() *
			Statics::GetActiveCamera()->GetViewMatrix() * GetMeshComponentMatrix());
	}

	void RenderComponent::SetShader(Shader* shader)
	{
		this->shader = shader;
	}
}