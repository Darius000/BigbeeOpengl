#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "World.h"
#include "BHive/UserInterface/Gui.h"

namespace BHive
{
	class BHIVE_API Application
	{
	public:
		Application();
		~Application();

		static int screenWidth;
		static int screenHeight;
		static glm::vec3 ClearColor;
		static bool firstMouse;
		static float lastX;
		static float lastY;

	private:
		static float deltaTime;
		static float lastTime;
		
		static int status;
		static GLFWwindow* window;
		DefaultUserInterface* userInterface;

	public:
		
		static float GetAspectRatio();
		static bool IsOpenGlInitializd();
	
	private:
		static bool openGLInitialized;
		static void ResizeWindow(GLFWwindow* inWindow, int width, int height);
		static void MouseInput(GLFWwindow* inWindow, double xpos, double ypos);
		static void MouseScroll(GLFWwindow* inWindow, double xOffset, double yOffset);
		void KeyboardInput(GLFWwindow* inWindow);
		void ProcessInput(int key);

		float GetDeltaTime();
		
		void SetOpenglStates();
		void PrintMaxVertexAttributes();
		void PrintOpenglInfo();
		void SetWindowHints();
		bool CreateOpenglWindow();
		void TerminateGLFW();
		static void UpdateViewPort();
		bool InitGLAD();
		bool InitOpengl();
		void SetCallBacks();
		void Render();	
		void CloseApp();

	public:
		int Run();
	};
}

#endif