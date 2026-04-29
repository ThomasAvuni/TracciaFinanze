//
// Created by thomas on 29/04/26.
//

#include "SingleExpenseView.h"

#include "imgui.h"

SingleExpenseView::SingleExpenseView(const Expense &expense) : m_Expense(expense){
    
}

void SingleExpenseView::Draw()
{
    ImGui::Separator();
    std::string name = "Nome: " + m_Expense.ExpenseName;
    ImGui::Text(name.c_str());
    std::string loc = "Posizione: " + m_Expense.Location;
    ImGui::Text(loc.c_str());
    std::string thingsBought = "Cosa hai comprato: " + m_Expense.ThingsBought;
    ImGui::Text(thingsBought.c_str());
    std::string amount = "Hai pagato Euro: " + std::to_string(m_Expense.Amount);
    ImGui::Text(amount.c_str());
    std::string date = "In data: " + std::to_string(m_Expense.Day) + "/" + std::to_string(m_Expense.Month) + "/" + std::to_string(m_Expense.Year);
    ImGui::Text(date.c_str());
    ImGui::Separator();
}
