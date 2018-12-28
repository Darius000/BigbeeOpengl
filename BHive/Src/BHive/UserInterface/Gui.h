#pragma once

#include "Core/Core.h"
#include "GLFW/glfw3.h"

namespace BHive
{
	class BHIVE_API GraphicsUserInterface
	{
	public:
		GraphicsUserInterface() {};

		virtual void DrawUserInterface() = 0;
	};

	class BHIVE_API DefaultUserInterface : public GraphicsUserInterface
	{
	public:
		DefaultUserInterface(GLFWwindow* window)
		{
		
		};

		void DrawUserInterface()
		{

		
			
		}
	};
}