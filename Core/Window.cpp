//
// Created by Thomas on 26/04/2026.

#include "Window.h"

#include <print>
#include <SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

Window::Window(const std::string& WindowName, int Width, int Height, bool EnableVSync) : m_WindowName(WindowName), m_Width(Width),
                                                                       m_Height(Height), m_pWindowHandle(nullptr),
                                                                       m_GLContext(nullptr) {
    InitSDL();
    SetVSyncEnabled(EnableVSync);
    InitImGui();
}

void Window::InitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::print("Errore impossibile inizializzare SDL {}\n", SDL_GetError());
        return;
    }
    m_pWindowHandle = SDL_CreateWindow(m_WindowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    m_GLContext = SDL_GL_CreateContext(m_pWindowHandle);
    SDL_GL_MakeCurrent(m_pWindowHandle, m_GLContext);
    SDL_GL_SetSwapInterval(m_EnableVSync);
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    }
}

void Window::InitImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.Fonts->AddFontFromFileTTF("../fonts/opensans/OpenSans-Regular.ttf");
    io.FontDefault = io.Fonts->AddFontFromFileTTF("../fonts/opensans/OpenSans-Regular.ttf");

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplSDL2_InitForOpenGL(m_pWindowHandle, m_GLContext);
    ImGui_ImplOpenGL3_Init("#version 130");
}
