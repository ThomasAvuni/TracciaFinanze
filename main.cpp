
#include "Core/Components/AddExpenseComponent.h"
#include "Core/Application.h"
#include <memory>
#include <print>

int main() {
    Application App("Traccia Finanze", 1280,  720);
    auto AddExpenseComp = std::make_shared<AddExpenseComponent>();
    App.PushComponent(AddExpenseComp);
    App.Run();
}
