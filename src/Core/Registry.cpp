#include <iostream>

#include "Core/Registry.hpp"

Registry& Registry::getInstance() {
    static Registry instance;
    return instance;
}

std::unique_ptr<GameObject> Registry::create(const std::string& className) {
    auto& factories = getInstance().m_factories;
    if(auto it = factories.find(className); it != factories.end()) {
        return it->second();
    }
    return nullptr;
}