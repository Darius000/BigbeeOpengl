#include "pch.h"
#include "ParticleEmitter.h"

namespace BHive
{
	Particle::Particle()
		:life(0.0f), velocity(glm::vec3(0.0f))
	{

	}

	Particle::~Particle()
	{
		//std::cout << "Particle Deleted\n";
	}

	void Particle::ComponentUpdate(float DeltaTime)
	{
		UpdatePosition(DeltaTime);
		UpdateColor(DeltaTime);

		life -= DeltaTime;

		if (life <= 0.0f)
		{
			Destroy();
		}

		BillboardComponent::ComponentUpdate(DeltaTime);
	}

	void Particle::UpdatePosition(float deltaTime)
	{
		SetPosition(GetPosition() + velocity * deltaTime);
	}

	void Particle::UpdateColor(float deltaTime)
	{
		color.a -= (deltaTime * .01f);
		size += (deltaTime * 2.0f);

		SetColor(color);
	}

	ParticleEmitter::ParticleEmitter()
		:texture(0), particles(0)
	{
		SetDisplayName("Particle Emitter");
	}


	ParticleEmitter::~ParticleEmitter()
	{

	}

	void ParticleEmitter::ComponentStart()
	{
		SetNumberParticles(20);

		lastUsedParticle = 0;
	}

	void ParticleEmitter::ComponentUpdate(float deltaTime)
	{
		static float time = 0.0f;

		unsigned int numNewParticles = 5;

		for (unsigned int i = 0; i < particles.size(); ++i)
		{
			particles[i]->ComponentUpdate(deltaTime);
		}

		if (time <= 0.0f)
		{
			//add new particle
			for (unsigned int i = 0; i < numNewParticles; ++i)
			{
				//int unusedParticle = FirstUnusedParticle();
				SpawnParticle();
			}

			time = 10.0f;
		}

		time -= 1.0f;
	}

	void ParticleEmitter::SetNumberParticles(unsigned int num)
	{
		//particles.empty();

		for (unsigned int i = 0; i < num; ++i)
		{
			SpawnParticle();
		}
	}

	void ParticleEmitter::SpawnParticle()
	{
		Particle* particle = new Particle();
		particle->ComponentStart();
		particles.push_back(particle);
		glm::vec3 random = glm::vec3((rand() % 100), (rand() % 100), (rand() % 100));
		glm::vec4 pcolor = color * ((rand() % 100) / 100.0f);
		particle->SetShader(shader);
		particle->SetPosition(GetParent()->GetRootComponent()->GetPosition() * random);
		particle->SetColor(pcolor);
		particle->SetTexture(texture);

		float size = ((rand() % 1) / .25f);
		float life = ((rand() % 5) - 1.0f);
		//std::cout << life << "\n";
		particle->life = life;
		particle->SetSize(size);

		glm::vec3 velocity = glm::vec3(
			((rand() % 5) - 2.5) / 5.0f,
			((rand() % 100) - 1.0f) / 100.0f,
			((rand() % 1) - .5));

		particle->velocity = velocity;
		particle->SetRotation(velocity);

		//std::cout << "Spawned Particle\n";
	}

	void ParticleEmitter::SetParticleTexture(Texture2D* particleTexture)
	{
		texture = particleTexture;
	}

	void ParticleEmitter::SetParticleColor(glm::vec4 particleColor)
	{
		color = particleColor;
	}

	void ParticleEmitter::SetParticleShader(Shader* inShader)
	{
		shader = inShader;
	}
}