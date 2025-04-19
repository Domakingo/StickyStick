#pragma once
#include <memory>
#include <unordered_map>
#include <string>
#include <functional>

#include "GameObjects/GameObject.hpp"

class Registry {
    public:
        template<typename T>
        static void registerType(const std::string& className) {
            getInstance().m_factories[className] = []() {
                return std::make_unique<T>();
            };
        }
        
        static std::unique_ptr<GameObject> create(const std::string& className);
        
    private:
        static Registry& getInstance();
        std::unordered_map<std::string, std::function<std::unique_ptr<GameObject>()>> m_factories;
    };