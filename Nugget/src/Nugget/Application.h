#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Nugget
{
	class NUGGET_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* CreateApplication();
}
