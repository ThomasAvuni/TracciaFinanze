//
// Created by Thomas on 26/04/2026.
//

#ifndef TRACCIAFINANZE_EXPENCESMANAGER_H
#define TRACCIAFINANZE_EXPENCESMANAGER_H
#include <string>

enum ExpenseType{
    None,
    Cloth,
    Food,
    Other
};

struct Expense {
    std::string ExpenseName;
    std::string Location;
    float Amount;
    int Year, Month, Day;
    ExpenseType Type;
};

class ExpencesManager {
    ExpencesManager() = default;

    void AddExpenses(Expense& expense);
    void RemoveExpense(Expense& expense);

    [[nodiscard]] ExpencesManager& Get() const {return *s_Instance;}

private:
    ExpencesManager *s_Instance = nullptr;
};


#endif //TRACCIAFINANZE_EXPENCESMANAGER_H
