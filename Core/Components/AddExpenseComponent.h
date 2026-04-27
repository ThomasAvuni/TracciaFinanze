//
// Created by Thomas on 26/04/2026.
//

#ifndef TRACCIAFINANZE_ADDEXPENSECOMPONENT_H
#define TRACCIAFINANZE_ADDEXPENSECOMPONENT_H
#include "../Component.h"


class AddExpenseComponent : public Component
{
public:
    AddExpenseComponent() = default;

    void OnAttach() override;
    void OnDetach() override;
    void OnUIUpdate() override;
};


#endif //TRACCIAFINANZE_ADDEXPENSECOMPONENT_H
