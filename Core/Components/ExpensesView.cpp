//
// Created by Thomas on 28/04/2026.
//

#include "ExpensesView.h"

#include "SingleExpenseView.h"
#include "../ExpensesManager.h"

static std::string str_tolower(std::string s)
{
    std::ranges::transform(s, s.begin(),
                           [](const unsigned char c){ return std::tolower(c); } 
    );
    return s;
}

ExpensesView::ExpensesView() {
    m_ExpenseManager = &ExpensesManager::Get();
}

void ExpensesView::OnUIUpdate() {
    Component::OnUIUpdate();

    ImGuiDraw("Vista Spese", [this] {
        const std::vector<Expense> expenses = m_ExpenseManager->LoadFromJSON();
        
        static char searchBuf[64] = "";
        
        ImGui::PushItemWidth(300.0f); 
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 20.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 8));
        
        ImGui::AlignTextToFramePadding();
        ImGui::TextDisabled("(?)"); 
        ImGui::SameLine();
        
        if (ImGui::InputTextWithHint("##Search", "Cerca per luogo...", searchBuf, sizeof(searchBuf))) { }
        
        ImGui::PopStyleVar(2);
        ImGui::PopItemWidth();
        
        ImGui::Spacing(); ImGui::Separator(); ImGui::Spacing();

        float windowWidth = ImGui::GetContentRegionAvail().x;
        int columnCount = static_cast<int>(windowWidth / 310.0f); 
        if (columnCount < 1) columnCount = 1;

        if (ImGui::BeginTable("ExpensesGrid", columnCount, ImGuiTableFlags_NoSavedSettings)) 
        {
            std::string searchStr = str_tolower(searchBuf);

            for (const Expense& e : expenses) 
            {
                if (!searchStr.empty()) {
                    if (str_tolower(e.Location).find(searchStr) == std::string::npos) {
                        continue;
                    }
                }

                ImGui::TableNextColumn();
                SingleExpenseView sev(e);
                sev.Draw();
                ImGui::Dummy(ImVec2(0.0f, 10.0f));
            }
            ImGui::EndTable();
        }
    });
}
