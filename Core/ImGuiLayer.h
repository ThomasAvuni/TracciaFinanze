//
// Created by Thomas on 27/04/2026.
//

#ifndef TRACCIAFINANZE_IMGUILAYER_H
#define TRACCIAFINANZE_IMGUILAYER_H
#include <string>

#include "imgui.h"


class ImGuiLayer {
public:
    ImGuiLayer() = default;

    template<typename F>
    static void ImGuiDraw(const std::string& name, F&& func) {
        ImGui::Begin(name.c_str());
        {
            func();
        }
        ImGui::End();
    }

private:
    void UIRender();
    friend class Application;
};

inline auto ImGuiDraw = [](const std::string& name, auto&& func) {
    ImGuiLayer::ImGuiDraw(name, std::forward<decltype(func)>(func));
};

#endif //TRACCIAFINANZE_IMGUILAYER_H
