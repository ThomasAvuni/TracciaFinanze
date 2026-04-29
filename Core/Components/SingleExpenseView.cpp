//
// Created by thomas on 29/04/26.
//

#include "SingleExpenseView.h"

#include "imgui.h"

SingleExpenseView::SingleExpenseView(const Expense &expense) : m_Expense(expense){
    
}

void SingleExpenseView::Draw()
{
    std::string name = "Nome: " + m_Expense.ExpenseName;
    ImGui::Text(name.c_str());
}
