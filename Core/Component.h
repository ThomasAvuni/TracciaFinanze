//
// Created by Thomas on 26/04/2026.
//

#ifndef TRACCIAFINANZE_COMPONENT_H
#define TRACCIAFINANZE_COMPONENT_H
#include <string>
#include "ImGuiLayer.h"
class Component {
public:
    Component(const std::string& Name = "Component");
    virtual ~Component() = default;

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUIUpdate() {}
    [[nodiscard]] const std::string& GetName() const {return m_Name;}
    [[nodiscard]] bool IsHidden() const {return m_Hidden;}
    void SetHidden(const bool& Hidden) {m_Hidden = Hidden;}
private:
    std::string m_Name;
    bool m_Hidden = false;
};


#endif //TRACCIAFINANZE_COMPONENT_H
