#include "pch.h"
#include "World.h"
#include "Components/RenderComponent.h"
#include "Components/BillboardComponent.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Image.h"
#include "Components/ParticleEmitter.h"
#include "Components/MeshComponent.h"
#include "Application.h"
#include "Core/Statics.h"

namespace BHive
{

	BHive::FPSCamera* World::DefaultCamera;

	World::World()
	{
		if (!Statics::GetWorld())
		{
			SetActive();
		}
	}


	World::~World()
	{
	}

	std::vector<std::unique_ptr<GameObject>> World::children;

	void World::RemoveChild(const GameObject& object)
	{
		auto it = std::find_if(children.begin(), children.end(), ErasePredicateUnique<GameObject>(object));

		children.erase(it);
	}

	void World::CreateWorld()
	{
		DefaultCamera = AddChild<FPSCamera>();
		DefaultCamera->aspectRatio = BHive::Application::GetAspectRatio();
		DefaultCamera->GetRootComponent()->SetPosition(glm::vec3(0.0f, 0.0f, 30.0f));
		DefaultCamera->GetRootComponent()->SetScale(1.0f);
		DefaultCamera->GetRootComponent()->SetRotation(0.0f, 0.0f, 0.0f);

		BHive::String string("new string");
		string[0] = 'B';

		BHive::String string2 = string;
		string2[1] = 'S';

		BHive::Print(string);
		BHive::Print(string2);

		GameObject* Cube = AddChild<GameObject>();
		BillboardComponent* BillboardComp = Cube->AddComponent<BillboardComponent>("Billboard");
		//BillboardComp->SetShader(SHD_Billboard);
		//BillboardComp->SetTexture(&T2D_Smoke);
		BillboardComp->SetBlendMode(2);
		BillboardComp->SetSize(100.0f);
		BillboardComp->SetColor(glm::vec4(0.6f, 0.3f, 0.0f, 1.0f));
		BillboardComp->SetPosition(2.0f, 2.0f, 0.0f);
		BillboardComp->SetScale(.5f);
		BillboardComp->SetRotation(25.f, 0.0f, 0.0f);

		/*GameObject* Particles = new GameObject();
		ParticleEmitter* SmokeEmitter = Particles->AddComponent<ParticleEmitter>("Particle Example");
		SmokeEmitter->SetParticleShader(SHD_Billboard);
		SmokeEmitter->SetParticleTexture(&T2D_Smoke);
		SmokeEmitter->SetParticleColor(glm::vec4(.3f, .2f, 0.0f, 1.0f));
		AddChild(Particles);*/
	}

	void World::RenderChildren(float deltaTime)
	{
		for (auto it = children.begin(); it != children.end();)
		{
			if (!(*it)->IsDestroyed())
			{
				(*it)->Update(deltaTime);
				++it;
			}
			else
			{
				it = children.erase(it);
			}

		}
	}

	void World::InitChildren()
	{
		CreateWorld();

		for (auto it = children.begin(); it != children.end(); ++it)
		{
			(*it)->Start();
		}
	}

	void World::SetActive()
	{
		Statics::SetWorld(this);

		if (Application::IsOpenGlInitializd())
		{
			InitChildren();
		}		
	}

}
