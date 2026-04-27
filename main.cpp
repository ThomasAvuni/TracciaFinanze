
#include "Core/Components/AddExpenseComponent.h"
#include "Core/Application.h"
#include <memory>
#include <print>

#include "Core/ExpensesManager.h"

int main() {
    Application App("Traccia Finanze", 1280,  720);
    ExpensesManager ExpensesManager{};
    auto AddExpenseComp = std::make_shared<AddExpenseComponent>();
    App.PushComponent(AddExpenseComp);
    App.Run();
}
