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
            const std::vector<Expense> expenses = m_ExpenseManager->LoadFromJSON();
        
            float windowWidth = ImGui::GetContentRegionAvail().x;
            int columnCount = (int)(windowWidth / 260.0f); // 350px + 10px di spazio
            if (columnCount < 1) columnCount = 2;

            if (ImGui::BeginTable("ExpensesGrid", columnCount, ImGuiTableFlags_None)) 
            {
                for (const Expense& e : expenses) 
                {
                    ImGui::TableNextColumn(); // Passa alla cella successiva (o riga successiva se la riga è piena)
                
                    SingleExpenseView sev(e);
                    sev.Draw();
                    ImGui::Dummy(ImVec2(0.0f, 20.0f));
                }
                ImGui::EndTable();
            }
        });
}
