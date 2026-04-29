
#include "Core/Components/AddExpenseComponent.h"
#include "Core/Application.h"
#include <memory>
#include <print>

#include "Core/ExpensesManager.h"
#include "Core/Components/ExpensesView.h"

int main() {
    Application App("Traccia Finanze", 1280,  720);
    ExpensesManager ExpensesManager{};
    auto AddExpenseComp = std::make_shared<AddExpenseComponent>();
    auto ExpenseView = std::make_shared<ExpensesView>();
    App.PushComponent(AddExpenseComp);
    App.PushComponent(ExpenseView);
    App.Run();
}
