#include "pch.h"
#include "EntryPoint.h"

BHive::Application* CreateApplication()
{
	return new BHive::Application();
}

int main(int argc, char** argv)
{
	BHive::World* defaultWorld = new BHive::World();
	BHive::Application* App = CreateApplication();
	App->Run();
	delete App;
	return 0;
}
