#pragma once
#include "Window.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"

class Engine {
public:
    static Engine& getInstance();
    
    void initialize();
    void start();
    void shutdown();
    
    Window& getWindow();
    InputHandler& getInputHandler();
    Game& getGame();

private:
    Engine() = default;
    void gameLoop();

    Window m_window;
    InputHandler m_inputHandler;
    Game m_game;
    bool m_running = false;
};