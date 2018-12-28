#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include "Components/RenderComponent.h"

namespace BHive
{
	class BHIVE_API CollisionComponent : public RenderComponent
	{
	public:
		CollisionComponent();
		~CollisionComponent();
	};
}

#endif