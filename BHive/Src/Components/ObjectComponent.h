#ifndef OBJECTCOMPONENT_H
#define OBJECTCOMPONENT_H


#include "Core/Object.h"

namespace BHive
{
	class GameObject;

	class BHIVE_API ObjectComponent : public Object
	{
	public:
		ObjectComponent();
		virtual ~ObjectComponent();

		virtual void ComponentStart();
		virtual void ComponentUpdate(float DeltaTime);
		void SetParent(GameObject* gameObject);
		GameObject* GetParent();

	private:
		GameObject* parent;
	};
}
#endif
