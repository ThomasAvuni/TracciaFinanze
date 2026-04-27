//
// Created by Thomas on 27/04/2026.
//

#include "ImGuiLayer.h"

#include <SDL_video.h>

#include "Application.h"
#include "Component.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_opengl3_loader.h"
#include "imgui_impl_sdl2.h"

void ImGuiLayer::UIRender()
{
    ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    {
        ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGuiWindowFlags dockspace_flags =
        ImGuiWindowFlags_NoTitleBar        |
        ImGuiWindowFlags_NoCollapse        |
        ImGuiWindowFlags_NoResize          |
        ImGuiWindowFlags_NoMove            |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoNavFocus        |
        ImGuiWindowFlags_NoBackground      |
        ImGuiWindowFlags_MenuBar;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 4.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.5f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
        ImGui::Begin("DockSpaceWindow", nullptr, dockspace_flags);
        ImGui::PopStyleVar(3);
        // DockSpace
        ImGui::DockSpace(ImGui::GetID("MainDockSpace"), ImVec2(0, 0),
            ImGuiDockNodeFlags_PassthruCentralNode);

        for (const auto& Comp : Application::Get().m_ComponentStack.GetComponents()) {
            if (Comp->IsHidden())
                continue;

            Comp->OnUIUpdate();
        }

        ImGui::End();
    }

    // --- Render ---
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        SDL_Window* backup_window = SDL_GL_GetCurrentWindow();
        SDL_GLContext backup_ctx  = SDL_GL_GetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        SDL_GL_MakeCurrent(backup_window, backup_ctx);
    }
}
