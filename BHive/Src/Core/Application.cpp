#include "pch.h"
#include "Application.h"
#include "GameObjects/Camera.h"
#include "Core/Statics.h"

namespace BHive
{
	Application::Application()
	{
		openGLInitialized = InitOpengl();

		userInterface = new DefaultUserInterface(window);
	}

	Application::~Application()
	{
		delete userInterface;
	}

	int Application::screenWidth = 1280;

	int Application::screenHeight = 760;

	glm::vec3 Application::ClearColor = glm::vec3(0.5f);

	bool Application::firstMouse = true;

	float Application::lastX = 0.0f;

	float Application::lastY = 0.0f;

	float Application::deltaTime = 0.0f;

	float Application::lastTime = 0.0f;

	int Application::status = 0;

	GLFWwindow* Application::window = 0;

	float Application::GetAspectRatio()
	{
		return (float)screenWidth / (float)screenHeight;
	}

	bool Application::IsOpenGlInitializd()
	{
		return openGLInitialized;
	}

	bool Application::openGLInitialized = false;

	void Application::ResizeWindow(GLFWwindow* inWindow, int width, int height)
	{
		screenWidth = width;
		screenHeight = height;
		UpdateViewPort();

	}

	void Application::MouseInput(GLFWwindow* inWindow, double xpos, double ypos)
	{
		if (firstMouse)
		{
			lastX = (float)xpos;
			lastY = (float)ypos;
			firstMouse = false;
		}

		float xOffset = (float)xpos - lastX;
		float yOffset = lastY - (float)ypos; //reverse since y coordinate is form bottom to top
		lastX = (float)xpos;
		lastY = (float)ypos;

		World::DefaultCamera->ProcessMouseMovement(xOffset, yOffset);
	}

	void Application::MouseScroll(GLFWwindow* inWindow, double xOffset, double yOffset)
	{
		World::DefaultCamera->ProcessMouseScroll((float)yOffset);
	}

	void Application::KeyboardInput(GLFWwindow* inWindow)
	{
		if (glfwGetKey(inWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			CloseApp();
		}
	}

	void Application::ProcessInput(int key)
	{
		//Call all objects that implement an input class
	}

	float Application::GetDeltaTime()
	{
		float currentTime = (float)glfwGetTime();

		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		return deltaTime;
	}

	void Application::SetOpenglStates()
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);
		glLineWidth(1.0f);
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void Application::PrintMaxVertexAttributes()
	{
		int attributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &attributes);
		std::cout << "Maximum number of vertex attributes supported:" << attributes << std::endl;
	}

	void Application::PrintOpenglInfo()
	{
		std::cout << glGetString(GL_VERSION) << std::endl;
	}

	void Application::SetWindowHints()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 8);
	}

	bool Application::CreateOpenglWindow()
	{
		window = glfwCreateWindow(screenWidth, screenHeight, "BHIVE", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create window" << std::endl;
			TerminateGLFW();
			status = -1;
			return false;
		}

		status = 0;

		glfwMakeContextCurrent(window);

		return true;
	}

	void Application::TerminateGLFW()
	{
		glfwTerminate();

	}

	void Application::UpdateViewPort()
	{
		glViewport(0, 0, screenWidth, screenHeight);
	}

	bool Application::InitGLAD()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialized GLAD" << std::endl;
			status = -1;
			return false;
		}

		status = 0;
		return true;
	}

	bool Application::InitOpengl()
	{
		glfwInit();

		SetWindowHints();

		if (!CreateOpenglWindow())
		{
			return false;
		}

		SetCallBacks();

		if (!InitGLAD())
		{
			return false;
		}

		SetOpenglStates();

		UpdateViewPort();

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		PrintMaxVertexAttributes();

		PrintOpenglInfo();

		return true;
	}

	void Application::SetCallBacks()
	{
		glfwSetFramebufferSizeCallback(window, ResizeWindow);
		glfwSetCursorPosCallback(window, MouseInput);
		glfwSetScrollCallback(window, MouseScroll);
	}

	void Application::Render()
	{
		Statics::GetWorld()->RenderChildren(GetDeltaTime());
	}

	int Application::Run()
	{
		/*if (!InitOpengl())
		{
			TerminateGLFW();

			openGLInitialized = false;

			return status;
		}*/

		//openGLInitialized = true;

		Statics::GetWorld()->InitChildren();

		while (!glfwWindowShouldClose(window))
		{
			KeyboardInput(window);

			glClearColor(ClearColor.x, ClearColor.y, ClearColor.z, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			Render();

			userInterface->DrawUserInterface();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		TerminateGLFW();

		return status;
	}

	void Application::CloseApp()
	{
		glfwSetWindowShouldClose(window, true);

	}
}
