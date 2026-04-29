//
// Created by Thomas on 26/04/2026.
//

#include "ExpensesManager.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <print>

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Expense, ExpenseName, Location, ThingsBought, Amount, Day, Month, Year, Type);
using json = nlohmann::json;

ExpensesManager *ExpensesManager::s_Instance = nullptr;

ExpensesManager::ExpensesManager() {
    s_Instance = this;
}

void ExpensesManager::AddExpense(Expense &expense)
{
    m_Expenses.push_back(expense);
}

void ExpensesManager::RemoveExpense(const Expense &expense) {
    auto it = std::find(m_Expenses.begin(), m_Expenses.end(), expense);
    if (it != m_Expenses.end()) {
        m_Expenses.erase(it);
    }
}

void ExpensesManager::SaveToJSON() {
    json j = m_Expenses;
    std::ofstream file(FilePath.string());

    if (file.is_open()) {
        file << j.dump(4);
        file.close();
        std::print("Spese salvate con successo\n");
    } else {
        std::print("Errore nel salvataggio\n");
    }

}

std::vector<Expense> ExpensesManager::LoadFromJSON() {
    std::ifstream file(FilePath.string());
    if (file.is_open()) {
        json j;
        file >> j;
        m_Expenses = j.get<std::vector<Expense>>();
        return m_Expenses;
    }
    std::print("Errore nel caricamento del file\n");
    return std::vector<Expense>{};
}
