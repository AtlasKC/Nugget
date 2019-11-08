#pragma once

#include "Core.h"
#include "Window.h"
#include "Nugget/LayerStack.h"
#include "Nugget/Events/Event.h"
#include "Nugget/Events/ApplicationEvent.h"

namespace Nugget
{
	class NUGGET_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}