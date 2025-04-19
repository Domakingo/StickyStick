#include "Core/Registry.hpp"

Registry& Registry::getInstance() {
    static Registry instance;
    return instance;
}

template<typename T>
void Registry::registerType(const std::string& className) {
    getInstance().m_factories[className] = []() {
        return std::make_unique<T>();
    };
}

std::unique_ptr<GameObject> Registry::create(const std::string& className) {
    auto& factories = getInstance().m_factories;
    if (auto it = factories.find(className); it != factories.end()) {
        return it->second();
    }
    return nullptr;
}

// Template instantiation for registered types
// (Add your GameObject-derived classes here)
// template void Registry::registerType<Player>(const std::string&);