#ifndef FPSCAMERA_H
#define FPSCAMERA_H


#include "Camera.h"

namespace BHive
{
	enum ECameraMovement
	{
		FOWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	//default values
	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float SPEED = 5.0f;
	const float SENSITIVITY = 0.1f;
	const float ZOOM = 45.0f;

	class BHIVE_API FPSCamera : public Camera
	{
	public:
		FPSCamera();
		FPSCamera(float AspectRatio);
		FPSCamera(float AspectRatio, glm::vec3 position, float Zoom = ZOOM, float yaw = YAW, float pitch = PITCH);

		//Euler Angles
		float Yaw;
		float Pitch;

		//Camera options
		float MovementSpeed;
		float MouseSensitvity;
		float Zoom;

		void ProcessKeyboard(ECameraMovement Direction, float deltaTime);

		void ProcessMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true);

		void ProcessMouseScroll(float yOffset);
	};
}
#endif