//
// Created by Thomas on 28/04/2026.
//

#include "ExpensesView.h"

#include "../ExpensesManager.h"

ExpensesView::ExpensesView() {
    m_ExpenseManager = &ExpensesManager::Get();
}

void ExpensesView::OnUIUpdate() {
    Component::OnUIUpdate();

    ImGuiDraw("Vista Spese", [this] {
        auto a = m_ExpenseManager->LoadFromJSON();
        std::string s = a[0].ExpenseName;
        ImGui::Text(s.c_str());
    });
}
