//
// Created by Thomas on 26/04/2026.
//

#ifndef TRACCIAFINANZE_EXPENSESMANAGER_H
#define TRACCIAFINANZE_EXPENSESMANAGER_H
#include <filesystem>
#include <string>
#include <vector>

enum ExpenseType{
    None,
    Cloth,
    Food,
    Other
};

struct Expense {
    std::string ExpenseName;
    std::string Location;
    std::string ThingsBought;
    float Amount;
    int Year, Month, Day;
    ExpenseType Type;

    // The compiler needs this to use std::find
    bool operator==(const Expense& other) const {
        return std::tie(ExpenseName, Location, ThingsBought, Amount, Year, Month, Day, Type) ==
               std::tie(other.ExpenseName, other.Location, other.ThingsBought, other.Amount,
                        other.Year, other.Month, other.Day, other.Type);
    }
};

inline static const char* ExpenseTypeLabels[] = {
    "Nessuna",
    "Abiti",
    "Cibo",
    "Altro"
};

class ExpensesManager {
public:
    ExpensesManager();

    void AddExpense(Expense& expense);
    void RemoveExpense(const Expense& expense);

    void SaveToJSON();
    std::vector<Expense> LoadFromJSON();

    [[nodiscard]] static ExpensesManager& Get() {return *s_Instance;}

    std::filesystem::path FilePath = "Spese/spese.json";

private:
    static ExpensesManager *s_Instance;
    std::vector<Expense> m_Expenses;
};


#endif //TRACCIAFINANZE_EXPENSESMANAGER_H
