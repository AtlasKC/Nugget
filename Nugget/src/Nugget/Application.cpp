#include "nepch.h"
#include "Application.h"

#include "Nugget/Events/ApplicationEvent.h"
#include "Nugget/Log.h"

namespace Nugget
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
		
	}

	void Application::run()
	{
		while(m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}