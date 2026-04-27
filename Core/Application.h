//
// Created by Thomas on 26/04/2026.
//

#ifndef TRACCIAFINANZE_APPLICATION_H
#define TRACCIAFINANZE_APPLICATION_H
#include <memory>
#include <string>

#include "ComponentStack.h"
#include "ImGuiLayer.h"
class Component;
class Window;

class Application {
public:
    Application(const std::string& WindowName, int Width, int Height, bool EnableVSync = true);
	static Application& Get() { return *s_Instance; }
    void Close();
    void Run();

    void PushComponent(std::shared_ptr<Component> Comp);
    void PopComponent(std::shared_ptr<Component> Comp);

    [[nodiscard]] Window& GetWindow() const {return *m_Window;}

private:
    std::shared_ptr<Window> m_Window;
    bool m_Running = true;

    static Application* s_Instance;
    ComponentStack m_ComponentStack;
    std::unique_ptr<ImGuiLayer> m_ImGuiLayer;
    friend class ImGuiLayer;
};


#endif //TRACCIAFINANZE_APPLICATION_H
