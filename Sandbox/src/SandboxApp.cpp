#include <Nugget.h>

class ExampleLayer : public Nugget::Layer
{
public:
	ExampleLayer() : Layer("Example") {}
	void OnUpdate() override { NE_INFO("ExampleLayer::Update"); }
	void OnEvent(Nugget::Event& event) override { NE_TRACE("{0}", event); }
};

class Sandbox : public Nugget::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Nugget::Application* Nugget::CreateApplication()
{
	return new Sandbox();
}