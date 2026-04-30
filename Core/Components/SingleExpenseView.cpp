//
// Created by thomas on 29/04/26.
//

#include "SingleExpenseView.h"

#include "imgui.h"

SingleExpenseView::SingleExpenseView(const Expense &expense) : m_Expense(expense){
    
}

void SingleExpenseView::Draw()
{
    ImGui::PushID(this);
    
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList *draw_list = ImGui::GetWindowDrawList();

    float rounding = 10.f;
    ImU32 coloreSfondo = ImGui::GetColorU32(ImGuiCol_ChildBg);
    ImU32 coloreBordo = ImGui::GetColorU32(ImGuiCol_Border);
    
    draw_list->AddRectFilled(p, ImVec2(p.x + 300.f, p.y + 150.f), coloreSfondo, rounding);
    draw_list->AddRect(p, ImVec2(p.x + 300.f, p.y + 150.f), coloreBordo, rounding);
    
    ImGui::BeginGroup();
    
    ImGui::SetCursorScreenPos(ImVec2(p.x + 10, p.y + 20));
    std::string name = "Nome: " + m_Expense.ExpenseName;
    ImGui::Text(name.c_str());
    
    ImGui::SetCursorScreenPos(ImVec2(p.x + 10, p.y + 40));
    std::string loc = "Posizione: " + m_Expense.Location;
    ImGui::Text(loc.c_str());
    
    ImGui::SetCursorScreenPos(ImVec2(p.x + 10, p.y + 60));
    std::string thingsBought = "Cosa hai comprato: " + m_Expense.ThingsBought;
    ImGui::Text(thingsBought.c_str());

    ImGui::SetCursorScreenPos(ImVec2(p.x + 10, p.y + 80));
    std::string amount = "Hai pagato Euro: " + std::to_string(m_Expense.Amount);
    ImGui::Text(amount.c_str());

    ImGui::SetCursorScreenPos(ImVec2(p.x + 10, p.y + 100));
    std::string date = "In data: " + std::to_string(m_Expense.Day) + "/" + std::to_string(m_Expense.Month) + "/" + std::to_string(m_Expense.Year);
    ImGui::Text(date.c_str());
    
    ImGui::EndGroup();
    ImGui::PopID();
}
