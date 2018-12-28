#ifndef PARTICLEEMIITERCOMPONENT_H
#define PARTICLEEMIITERCOMPONENT_H


#include "GameObjects/GameObject.h"
#include "Components/BillboardComponent.h"

namespace BHive
{
	class BHIVE_API Particle : public BillboardComponent
	{
	public:
		Particle();
		~Particle();

		virtual void ComponentUpdate(float DeltaTime) override;
		void UpdatePosition(float deltaTime);
		void UpdateColor(float deltaTime);

		float life;
		glm::vec3 velocity;
	};

	class BHIVE_API ParticleEmitter : public RenderComponent
	{
	public:
		ParticleEmitter();
		~ParticleEmitter();

		virtual void ComponentStart() override;
		virtual void ComponentUpdate(float deltaTime) override;

		void SetNumberParticles(unsigned int num);
		void SpawnParticle();
		void SetParticleTexture(Texture2D* particleTexture);
		void SetParticleColor(glm::vec4 particleColor);
		void SetParticleShader(Shader* inShader);

		std::vector<Particle*> particles;

	protected:
		Texture2D* texture;
		glm::vec4 color;

	private:
		unsigned int lastUsedParticle;
	};
}
#endif