#include "pch.h"
#include "Object.h"


namespace BHive
{
	Object::Object()
		:displayName("Object"), destroyed(false)
	{

	}

	Object::~Object()
	{

	}

	String Object::GetDisplayName()
	{
		return displayName;
	}

	String Object::GetClassDisplayName()
	{
		return String(typeid(this).name());
	}

	void Object::SetDisplayName(const String& string)
	{
		displayName = string;
	}

	void Object::Destroy()
	{
		destroyed = true;

		DestroyOptions();
	}

	bool Object::IsDestroyed()
	{
		return destroyed;
	}

	void Object::DestroyOptions()
	{

	}

}