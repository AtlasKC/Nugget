#include "nepch.h"
#include "Application.h"

#include "Nugget/Events/ApplicationEvent.h"
#include "Nugget/Log.h"

namespace Nugget
{
	Application::Application()
	{

	}

	Application::~Application()
	{
		
	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			NE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			NE_TRACE(e);
		}
		while(true);
	}
}