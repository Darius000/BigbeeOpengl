#include "pch.h"
#include "Statics.h"

BHive::Camera* BHive::Statics::GetActiveCamera()
{
	return currentCamera;
}

BHive::World* BHive::Statics::GetWorld()
{
	return currentWorld;
}

void BHive::Statics::SetActiveCamera(Camera* camera)
{
	currentCamera = camera;
}

void BHive::Statics::SetWorld(World* world)
{
	currentWorld = world;
}

BHive::Camera* BHive::Statics::currentCamera;

BHive::World* BHive::Statics::currentWorld;
