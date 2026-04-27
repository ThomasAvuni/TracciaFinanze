//
// Created by Thomas on 26/04/2026.
//

#include "ComponentStack.h"

#include "Component.h"

ComponentStack::~ComponentStack() {
    for (auto& comp : m_Components) {
        comp->OnDetach();
    }
}

void ComponentStack::PushComponent(std::shared_ptr<Component> Comp) {
    m_Components.emplace(m_Components.begin() + m_ComponentsCount, Comp);
    m_ComponentsCount++;
}

void ComponentStack::PopComponent(std::shared_ptr<Component> Comp) {
    auto it = std::find(m_Components.begin(), m_Components.begin() + m_ComponentsCount, Comp);
    if (it != m_Components.begin() + m_ComponentsCount) {
        (*it)->OnDetach();
        m_Components.erase(it);
        m_ComponentsCount--;
    }
}
