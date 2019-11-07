#pragma once

#ifdef NE_PLATFORM_WINDOWS

extern Nugget::Application* Nugget::CreateApplication();

int main(int argc, char** argv)
{
	printf("Nugget Engine - 0.0.1a...\n");
	auto app = Nugget::CreateApplication();
	app->run();
	delete app;
}
#endif