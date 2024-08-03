
/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class PauseState.
*/

#include "PauseState.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Settings.hpp"
#include "StateMachine.hpp"
#include "text_utilities.hpp"

PauseState::PauseState(StateMachine* sm) noexcept
    : BaseState{sm}
{
}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
{
    world = _world;
    bird = _bird;
}

void PauseState::exit() noexcept
{
    world = nullptr;
    bird = nullptr;
}

void PauseState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
    {
        state_machine->change_state("playing", world, bird);
    }
}

void PauseState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);

    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2, "Paused", Settings::HUGE_TEXT_SIZE, "font", sf::Color::White, true);
}
