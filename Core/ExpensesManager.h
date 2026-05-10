//
// Created by Thomas on 26/04/2026.
//

#ifndef TRACCIAFINANZE_EXPENSESMANAGER_H
#define TRACCIAFINANZE_EXPENSESMANAGER_H
#include <filesystem>
#include <string>
#include <utility>
#include <vector>
#include <nlohmann/json_fwd.hpp>
#include <boost/uuid/uuid.hpp>            // Struttura dati uuid
#include <boost/uuid/uuid_generators.hpp> // Generatori (random, name-based, ecc.)
#include <boost/uuid/uuid_io.hpp>

using json = nlohmann::json;
using namespace boost;
namespace fs = std::filesystem;

enum ExpenseType{
    None,
    Cloth,
    Food,
    Other
};

struct Expense {
    Expense()
    {
        static uuids::random_generator gen;
        UUID = uuids::to_string(gen());
    }

    std::string ExpenseName;
    std::string Location;
    std::string ThingsBought;
    float Amount{};
    int Year{}, Month{}, Day{};
    ExpenseType Type{};

    const std::string& GetUUID() {return UUID;}
    
    bool operator==(const Expense& other) const {
        return UUID == other.UUID;
    }
    
private:
    
    friend void to_json(nlohmann::json& j, const Expense& e);
    friend void from_json(const nlohmann::json& j, Expense& e);
    
    std::string UUID;
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
    void EditExpense(const Expense& expense, const Expense& newExpense);
    
    void SaveToJSON();
    std::vector<Expense> LoadFromJSON();

    std::string GetStringUUID();    
    
    [[nodiscard]] static ExpensesManager& Get() {return *s_Instance;}

private:
    fs::path GetDocumentsPath();
    
    static ExpensesManager *s_Instance;
    std::vector<Expense> m_Expenses;
    uuids::random_generator m_Gen;
};



#endif //TRACCIAFINANZE_EXPENSESMANAGER_H
