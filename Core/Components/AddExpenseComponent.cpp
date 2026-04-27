//
// Created by Thomas on 26/04/2026.
//

#include "AddExpenseComponent.h"
#include <print>
#include "imgui.h"

void AddExpenseComponent::OnAttach()
{
    std::print("Expense Comp attached\n");
}

void AddExpenseComponent::OnDetach()
{

}

void AddExpenseComponent::OnUIUpdate()
{
    {
        ImGuiDraw("Aggiungi una nuova spesa", [] {
            ImGui::Text("Prova");
        });
    }
}
