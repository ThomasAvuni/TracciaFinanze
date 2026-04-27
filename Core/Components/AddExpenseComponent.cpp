//
// Created by Thomas on 26/04/2026.
//

#include "AddExpenseComponent.h"

#include <algorithm>
#include <print>
#include "imgui.h"
#include "../ExpensesManager.h"

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
            static char ExpenseName[64];
            ImGui::Text("Nome Spesa");
            ImGui::SetNextItemWidth(200);
            ImGui::InputText(" ##NomeSpesa", ExpenseName, sizeof(ExpenseName));
            static char LocationName[64];
            ImGui::Text("Nome Location");
            ImGui::SetNextItemWidth(200);
            ImGui::InputText("##NomeLocation", LocationName, sizeof(LocationName));
            static float Amount = 0.f;
            ImGui::Text("Solid Spesi");
            ImGui::SetNextItemWidth(200);
            ImGui::InputFloat("##SoldiSpesi", &Amount);

            ImGui::Text("Categoria");
            ImGui::SetNextItemWidth(200);
            static ExpenseType SelectedType = None;
            if (ImGui::BeginCombo("##Categoria", ExpenseTypeLabels[static_cast<int>(SelectedType)])) {
                for (int i = 0; i < IM_ARRAYSIZE(ExpenseTypeLabels); i++) {
                    bool selected = (static_cast<int>(SelectedType) == i);
                    if (ImGui::Selectable(ExpenseTypeLabels[i], selected))
                        SelectedType = static_cast<ExpenseType>(i);
                    else
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndCombo();
            }

            ImGui::NewLine();

            static int Day = 1, Month = 1, Year = 2026;
            ImGui::SetNextItemWidth(50);
            ImGui::InputInt("##g", &Day, 0, 0);
            ImGui::SameLine(); ImGui::Text("/");
            ImGui::SameLine();
            ImGui::SetNextItemWidth(50);
            ImGui::InputInt("##m", &Month, 0, 0);
            ImGui::SameLine(); ImGui::Text("/");
            ImGui::SameLine();
            ImGui::SetNextItemWidth(50);
            ImGui::InputInt("##a", &Year, 0, 0);
            Day = std::clamp(Day, 1, 31);
            Month = std::clamp(Month, 1, 12);
            Year = std::clamp(Year, 2000, 2100);

            bool NameEmpty     = strlen(ExpenseName) == 0;
            bool LocationEmpty = strlen(LocationName) == 0;
            bool AmountInvalid = Amount <= 0.f;
            bool TypeInvalid   = SelectedType == None;

            if (NameEmpty)     ImGui::TextColored(ImVec4(1,0.3f,0.3f,1), "* Inserisci un nome spesa");
            if (LocationEmpty) ImGui::TextColored(ImVec4(1,0.3f,0.3f,1), "* Inserisci una location");
            if (AmountInvalid) ImGui::TextColored(ImVec4(1,0.3f,0.3f,1), "* Inserisci un importo valido");
            if (TypeInvalid)   ImGui::TextColored(ImVec4(1,0.3f,0.3f,1), "* Seleziona una categoria");

            bool HasErrors = NameEmpty || LocationEmpty || AmountInvalid || TypeInvalid;
            if (HasErrors)
                ImGui::BeginDisabled();

            Expense e{ExpenseName, LocationName, Amount, Year, Month, Day, SelectedType};
            ImGui::NewLine();
            if (ImGui::Button("Aggiungi", ImVec2(200, 0))) {
                ExpensesManager::Get().AddExpenses(e);
                ExpensesManager::Get().SaveToJSON();
            }

            if (HasErrors)
                ImGui::EndDisabled();
        });
    }
}
