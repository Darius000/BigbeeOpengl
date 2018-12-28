#ifndef CAMERA_H
#define CAMERA_H


#include "GameObjects/GameObject.h"

namespace BHive
{
	class BHIVE_API Camera : public GameObject
	{
	public:
		Camera();
		Camera(float AspectRatio);
		Camera(float AspectRatio, glm::vec3 position);
		virtual ~Camera();

		float Fov;
		float Near;
		float Far;
		float aspectRatio;

		void SetActive();
		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjectionMatrix();
		glm::mat4 LookAt(glm::vec3 target);
	};
}
#endif