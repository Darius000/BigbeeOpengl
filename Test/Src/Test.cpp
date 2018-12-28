#include <BHive.h>

class Test : public BHive::Application
{
public:
	Test()
	{

	};

	~Test()
	{

	};
};

BHive::Application* CreateApplication()
{
	return new Test();

}
