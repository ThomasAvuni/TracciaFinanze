//
// Created by thomas on 29/04/26.
//

#include "SingleExpenseView.h"

#include "imgui.h"

SingleExpenseView::SingleExpenseView(const Expense &expense) : m_Expense(expense){
    
}

const char* GetTypeString(ExpenseType type) {
    switch (type) {
    case ExpenseType::Food:       return "Alimentari";
    case ExpenseType::Cloth:  return "Vestiti";
    case ExpenseType::Other:      return "Altro";
    }
}

void SingleExpenseView::Draw()
{
    ImGui::PushID(m_Expense.GetUUID().c_str()); 
    
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 10.f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::GetStyleColorVec4(ImGuiCol_FrameBg));
    
    if (ImGui::BeginChild(("ExpenseCard##" + m_Expense.GetUUID()).c_str(), ImVec2(300, 0), ImGuiChildFlags_AutoResizeY)) 
    {
        ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 10.f, ImGui::GetCursorPos().y + 10.f));
        
        ImGui::BeginGroup(); 
        
        float contentWidth = ImGui::GetContentRegionAvail().x - 10.f; // Larghezza utile meno margine destro
    
        ImGui::TextColored(ImVec4(0.4f, 0.8f, 1.0f, 1.0f), "DETTAGLIO");
        ImGui::SameLine(contentWidth - 75.f);
        ImGui::TextDisabled("%02d/%02d/%d", m_Expense.Day, m_Expense.Month, m_Expense.Year);
    
        ImGui::Separator();
    
        ImGui::PushTextWrapPos(ImGui::GetCursorPos().x + contentWidth); 
    
        ImGui::Text("Nome: %s", m_Expense.ExpenseName.c_str());
        
        ImGui::Text("Categoria: "); ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "%s", GetTypeString(m_Expense.Type));
        
        ImGui::Text("Posizione: %s", m_Expense.Location.c_str());
        ImGui::Text("Cosa: %s", m_Expense.ThingsBought.c_str());
    
        ImGui::PopTextWrapPos();
    
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
    
        ImGui::Text("Totale:"); ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "%.2f EUR", m_Expense.Amount);
    
        ImGui::SameLine(contentWidth - 75.f);
        
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.6f, 0.1f, 0.1f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.8f, 0.1f, 0.1f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.4f, 0.1f, 0.1f, 1.0f));
        
        if (ImGui::Button("Cancella"))
        {
            ExpensesManager::Get().RemoveExpense(m_Expense);
        }
        ImGui::PopStyleColor(3);
        
        ImGui::Spacing();
        
        ImGui::EndGroup();
    }
    ImGui::EndChild();
    
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
    ImGui::PopID();
}