//
// Created by Thomas on 28/04/2026.
//

#include "ExpensesView.h"

#include "SingleExpenseView.h"
#include "../ExpensesManager.h"

ExpensesView::ExpensesView() {
    m_ExpenseManager = &ExpensesManager::Get();
}

void ExpensesView::OnUIUpdate() {
    Component::OnUIUpdate();

    ImGuiDraw("Vista Spese", [this] {
        for (const std::vector<Expense> expenses = m_ExpenseManager->LoadFromJSON(); const Expense& e : expenses)
        {
            SingleExpenseView sev(e);
            sev.Draw();
            ImGui::NewLine();
        }
    });
}
