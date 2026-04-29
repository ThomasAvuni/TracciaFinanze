//
// Created by Thomas on 28/04/2026.
//

#ifndef TRACCIAFINANZE_EXPENSESVIEW_H
#define TRACCIAFINANZE_EXPENSESVIEW_H
#include "../Component.h"


class ExpensesManager;

class ExpensesView : public Component
{
public:
    ExpensesView();

protected:
    void OnUIUpdate() override;
private:
    ExpensesManager *m_ExpenseManager;
};

#endif //TRACCIAFINANZE_EXPENSESVIEW_H
