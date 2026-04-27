//
// Created by Thomas on 26/04/2026.
//

#include "Application.h"
#include <SDL.h>
#include <SDL_events.h>
#include "Component.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl2.h"
#include "Window.h"

Application* Application::s_Instance = nullptr;

Application::Application(const std::string &WindowName, int Width, int Height, bool EnableVSync) {
    s_Instance = this;

    m_Window = std::make_shared<Window>(WindowName, Width, Height, EnableVSync);
    m_ImGuiLayer = std::make_unique<ImGuiLayer>();
}

void Application::PushComponent(std::shared_ptr<Component> Comp) {
    m_ComponentStack.PushComponent(Comp);
    Comp->OnAttach();
}

void Application::PopComponent(std::shared_ptr<Component> Comp) {
    m_ComponentStack.PopComponent(Comp);
    Comp->OnDetach();
}

void Application::Close() {
    m_Running = false;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_GL_DeleteContext(m_Window->GetGLContext());
    SDL_DestroyWindow(m_Window->GetWindowHandle());
    SDL_Quit();
}

void Application::Run() {
    while (m_Running)
    {
        m_ImGuiLayer->UIRender();
        SDL_GL_SwapWindow(m_Window->GetWindowHandle());

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
            {
                Close();
                break;
            }
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(m_Window->GetWindowHandle()))
            {
                Close();
                break;
            }
        }
    }
}