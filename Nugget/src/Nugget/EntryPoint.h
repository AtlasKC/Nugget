#pragma once

#ifdef NE_PLATFORM_WINDOWS

extern Nugget::Application* Nugget::CreateApplication();

int main(int argc, char** argv)
{
	Nugget::Log::init();
	NE_CORE_INFO("Core initialized...");
	NE_INFO("App initialized...");
	auto app = Nugget::CreateApplication();
	app->Run();
	delete app;
}

#endif