/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Anthony Dugarte
    toonny1998@gmail.com

    This file contains the declaration of the class PauseState.
*/

#pragma once

#include "BaseState.hpp"
#include "World.hpp"

class PauseState : public BaseState
{
public:
    PauseState(StateMachine* sm) noexcept;

    void enter(std::shared_ptr<World> _world = nullptr, std::shared_ptr<Bird> _bird = nullptr) noexcept override;

    void exit() noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

    void handle_inputs(const sf::Event& event) noexcept override;

private:
    std::shared_ptr<World> world;
    std::shared_ptr<Bird> bird;
};
