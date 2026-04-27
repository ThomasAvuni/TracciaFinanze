//
// Created by Thomas on 26/04/2026.
//
#ifndef TRACCIAFINANZE_COMPONENTSTACK_H
#define TRACCIAFINANZE_COMPONENTSTACK_H

#include "base.h"
#include <memory>

class Component;

class ComponentStack {
public:
    ComponentStack() = default;
    ~ComponentStack();
    void PushComponent(std::shared_ptr<Component> Comp);
    void PopComponent(std::shared_ptr<Component> Comp);

    [[nodiscard]] const std::vector<std::shared_ptr<Component>>& GetComponents() const {return m_Components;}

private:
    std::vector<std::shared_ptr<Component>> m_Components;
    unsigned int m_ComponentsCount{};
};


#endif //TRACCIAFINANZE_COMPONENTSTACK_H
