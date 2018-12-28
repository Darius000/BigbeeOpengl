#ifndef STATICS_H
#define STATICS_H

#include "Core/World.h"
#include "GameObjects/Camera.h"

namespace BHive
{
	class Statics
	{
	public:
		Statics() = delete;
		~Statics() = delete;
		Statics(const Statics& stat) = delete;

		static Camera* GetActiveCamera();
		static World* GetWorld();

		static void SetActiveCamera(Camera* camera);
		static void SetWorld(World* world);

	private:
		static Camera* currentCamera;
		static World* currentWorld;
	};
}


#endif // STATICS_H
