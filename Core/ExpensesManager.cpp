#include "ExpensesManager.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <print>
#include <algorithm>
#include <iostream>


void to_json(json& j, const Expense& e) {
    j = json{
        {"UUID", e.UUID},
        {"ExpenseName", e.ExpenseName},
        {"Location", e.Location},
        {"ThingsBought", e.ThingsBought},
        {"Amount", e.Amount},
        {"Day", e.Day},
        {"Month", e.Month},
        {"Year", e.Year},
        {"Type", e.Type}
    };
}

void from_json(const json& j, Expense& e) {
    j.at("UUID").get_to(e.UUID);
    j.at("ExpenseName").get_to(e.ExpenseName);
    j.at("Location").get_to(e.Location);
    j.at("ThingsBought").get_to(e.ThingsBought);
    j.at("Amount").get_to(e.Amount);
    j.at("Day").get_to(e.Day);
    j.at("Month").get_to(e.Month);
    j.at("Year").get_to(e.Year);
    j.at("Type").get_to(e.Type);
}

ExpensesManager* ExpensesManager::s_Instance = nullptr;

ExpensesManager::ExpensesManager() {
    if (!s_Instance) s_Instance = this;
}

void ExpensesManager::AddExpense(Expense& expense) {
    m_Expenses.push_back(expense);
}

void ExpensesManager::RemoveExpense(const Expense& expense) {
    auto it = std::find(m_Expenses.begin(), m_Expenses.end(), expense);
    if (it != m_Expenses.end()) {
        m_Expenses.erase(it);
        SaveToJSON();
    }
}

void ExpensesManager::SaveToJSON() {
    fs::path filePath = GetDocumentsPath() / "Spese.json";
    std::ofstream file(filePath); 

    if (file.is_open()) {
        json j = m_Expenses; 
        file << j.dump(4);
        std::print("Spese salvate con successo\n");
    } else {
        std::print("Errore nel salvataggio: impossibile aprire il file\n");
    }
}

std::vector<Expense> ExpensesManager::LoadFromJSON()
{
    fs::path filePath = GetDocumentsPath() / "Spese.json";
    std::ifstream file(filePath);
    
    if (!file.is_open()) {
        std::print("Nessun salvataggio trovato o errore nel caricamento\n");
        return {};
    }

    try {
        json j;
        file >> j;
        m_Expenses = j.get<std::vector<Expense>>();
        return m_Expenses;
    } catch (const json::exception& e) {
        std::cout<<"Errore nel parsing json "<< e.what()<<"\n";
        return {};
    }
}

fs::path ExpensesManager::GetDocumentsPath()
{
    std::string home;
#if WIN32
    home = std::getenv("USERPROFILE");
#else
    home = std::getenv("HOME");
#endif
    
    fs::path docs = fs::path(home) / "Documents";
    fs::path projectFolder = docs / "TracciaFinanze";
    if (!fs::exists(projectFolder))
    {
        fs::create_directories(projectFolder);
    }
    
    return projectFolder;
}