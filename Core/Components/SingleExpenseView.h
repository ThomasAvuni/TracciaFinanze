//
// Created by thomas on 29/04/26.
//

#ifndef TRACCIAFINANZE_SINGLEEXPENSEVIEW_H
#define TRACCIAFINANZE_SINGLEEXPENSEVIEW_H


#include "../ExpensesManager.h"

class SingleExpenseView {
public:
    SingleExpenseView(const Expense& expense);
    
    void Draw();
    
private:
    Expense m_Expense; 
};


#endif //TRACCIAFINANZE_SINGLEEXPENSEVIEW_H
