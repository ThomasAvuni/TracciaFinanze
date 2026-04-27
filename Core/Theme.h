//
// Created by Thomas on 27/04/2026.
//

#ifndef TRACCIAFINANZE_THEME_H
#define TRACCIAFINANZE_THEME_H

#include "imgui.h"

inline void ApplyTheme()
{
    ImGuiStyle& s = ImGui::GetStyle();

    // --- Bordi arrotondati ---
    s.WindowRounding    = 10.0f;
    s.ChildRounding     = 8.0f;
    s.FrameRounding     = 6.0f;
    s.PopupRounding     = 8.0f;
    s.ScrollbarRounding = 6.0f;
    s.GrabRounding      = 6.0f;
    s.TabRounding       = 6.0f;

    // --- Spaziatura ---
    s.WindowPadding     = ImVec2(14, 14);
    s.FramePadding      = ImVec2(10, 6);
    s.ItemSpacing       = ImVec2(10, 8);
    s.ItemInnerSpacing  = ImVec2(8, 6);
    s.ScrollbarSize     = 10.0f;
    s.GrabMinSize       = 10.0f;
    s.WindowBorderSize  = 0.0f;
    s.FrameBorderSize   = 0.0f;
    s.PopupBorderSize   = 1.0f;

    // --- Palette ---
    ImVec4* c = s.Colors;

    // Sfondo
    c[ImGuiCol_WindowBg]          = ImVec4(0.09f, 0.09f, 0.12f, 1.00f);
    c[ImGuiCol_ChildBg]           = ImVec4(0.11f, 0.11f, 0.15f, 1.00f);
    c[ImGuiCol_PopupBg]           = ImVec4(0.11f, 0.11f, 0.15f, 1.00f);

    // Titolo finestra
    c[ImGuiCol_TitleBg]           = ImVec4(0.07f, 0.07f, 0.10f, 1.00f);
    c[ImGuiCol_TitleBgActive]     = ImVec4(0.13f, 0.10f, 0.22f, 1.00f);
    c[ImGuiCol_TitleBgCollapsed]  = ImVec4(0.07f, 0.07f, 0.10f, 1.00f);

    // Accento viola/indaco
    c[ImGuiCol_CheckMark]         = ImVec4(0.60f, 0.45f, 1.00f, 1.00f);
    c[ImGuiCol_SliderGrab]        = ImVec4(0.55f, 0.40f, 0.95f, 1.00f);
    c[ImGuiCol_SliderGrabActive]  = ImVec4(0.70f, 0.55f, 1.00f, 1.00f);

    // Bottoni
    c[ImGuiCol_Button]            = ImVec4(0.28f, 0.20f, 0.55f, 1.00f);
    c[ImGuiCol_ButtonHovered]     = ImVec4(0.38f, 0.28f, 0.70f, 1.00f);
    c[ImGuiCol_ButtonActive]      = ImVec4(0.50f, 0.38f, 0.85f, 1.00f);

    // Frame (InputText, Combo, ecc.)
    c[ImGuiCol_FrameBg]           = ImVec4(0.15f, 0.14f, 0.20f, 1.00f);
    c[ImGuiCol_FrameBgHovered]    = ImVec4(0.20f, 0.18f, 0.28f, 1.00f);
    c[ImGuiCol_FrameBgActive]     = ImVec4(0.24f, 0.22f, 0.34f, 1.00f);

    // Header (Selectable, CollapsingHeader)
    c[ImGuiCol_Header]            = ImVec4(0.28f, 0.20f, 0.55f, 0.70f);
    c[ImGuiCol_HeaderHovered]     = ImVec4(0.38f, 0.28f, 0.70f, 0.80f);
    c[ImGuiCol_HeaderActive]      = ImVec4(0.50f, 0.38f, 0.85f, 1.00f);

    // Tab
    c[ImGuiCol_Tab]               = ImVec4(0.13f, 0.12f, 0.18f, 1.00f);
    c[ImGuiCol_TabHovered]        = ImVec4(0.38f, 0.28f, 0.70f, 1.00f);
    c[ImGuiCol_TabActive]         = ImVec4(0.28f, 0.20f, 0.55f, 1.00f);
    c[ImGuiCol_TabUnfocused]      = ImVec4(0.10f, 0.10f, 0.14f, 1.00f);
    c[ImGuiCol_TabUnfocusedActive]= ImVec4(0.18f, 0.15f, 0.28f, 1.00f);

    // Scrollbar
    c[ImGuiCol_ScrollbarBg]       = ImVec4(0.09f, 0.09f, 0.12f, 1.00f);
    c[ImGuiCol_ScrollbarGrab]     = ImVec4(0.28f, 0.20f, 0.55f, 1.00f);
    c[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.38f, 0.28f, 0.70f, 1.00f);
    c[ImGuiCol_ScrollbarGrabActive]  = ImVec4(0.50f, 0.38f, 0.85f, 1.00f);

    // Separatori e bordi
    c[ImGuiCol_Separator]         = ImVec4(0.25f, 0.22f, 0.35f, 1.00f);
    c[ImGuiCol_SeparatorHovered]  = ImVec4(0.50f, 0.38f, 0.85f, 1.00f);
    c[ImGuiCol_SeparatorActive]   = ImVec4(0.60f, 0.45f, 1.00f, 1.00f);
    c[ImGuiCol_Border]            = ImVec4(0.22f, 0.20f, 0.30f, 1.00f);

    // Testo
    c[ImGuiCol_Text]              = ImVec4(0.92f, 0.90f, 1.00f, 1.00f);
    c[ImGuiCol_TextDisabled]      = ImVec4(0.45f, 0.42f, 0.55f, 1.00f);

    // Docking
    c[ImGuiCol_DockingPreview]    = ImVec4(0.55f, 0.40f, 0.95f, 0.50f);
    c[ImGuiCol_DockingEmptyBg]    = ImVec4(0.07f, 0.07f, 0.10f, 1.00f);

    // Resize grip
    c[ImGuiCol_ResizeGrip]        = ImVec4(0.28f, 0.20f, 0.55f, 0.50f);
    c[ImGuiCol_ResizeGripHovered] = ImVec4(0.50f, 0.38f, 0.85f, 0.80f);
    c[ImGuiCol_ResizeGripActive]  = ImVec4(0.60f, 0.45f, 1.00f, 1.00f);

    // Menu
    c[ImGuiCol_MenuBarBg]         = ImVec4(0.07f, 0.07f, 0.10f, 1.00f);
}

#endif //TRACCIAFINANZE_THEME_H
