#ifndef WORLD_H
#define  WORLD_H

#include "GameObjects/GameObject.h"
#include "GameObjects/FPSCamera.h"

namespace BHive
{
	class BHIVE_API World
	{
	public:
		static FPSCamera* DefaultCamera;

	public:
		World();
		virtual ~World();

		static std::vector<std::unique_ptr<GameObject>> children;

		template<class T>
		T* AddChild();

		void RemoveChild(const GameObject& object);

		//Override Create World in subclasses. Default includes preview
		virtual void CreateWorld();

		void RenderChildren(float deltaTime);

		void InitChildren();

		void SetActive();	
	};

	template<class T> 
	T* BHive::World::AddChild()
	{
		auto it = std::unique_ptr<T>(new T());
		T* itRef = it.get();
		children.push_back(std::move(it));
		return itRef;
	}
}

#endif 

