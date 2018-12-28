#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "Components/TransformComponent.h"
#include "Core/Object.h"

namespace BHive
{
	const glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);


	class BHIVE_API GameObject : public Object
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Start();
		virtual void Update(float deltaTime);
		void SetRootComponent(TransformComponent* component);
		TransformComponent* GetRootComponent();
		bool IsDestroyed();
		virtual void DestroyOptions() override;

		template<typename T>
		T* AddComponent(std::string name);

	private:

		std::vector<std::unique_ptr<ObjectComponent>> components;

		TransformComponent* rootComponent;

		bool destroyed;
	};

	template<class T>
	T* GameObject::AddComponent(std::string name)
	{
		auto component = std::unique_ptr<T>(new T());

		component->SetParent(this);

		T* componentReference = component.get();

		components.push_back(std::move(component));

		return componentReference;
	}
}
#endif