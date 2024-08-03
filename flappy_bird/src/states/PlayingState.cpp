/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class PlayingBaseState.
*/

#include "PlayingState.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Settings.hpp"
#include "StateMachine.hpp"
#include "text_utilities.hpp"

PlayingState::PlayingState(StateMachine* sm) noexcept
    : BaseState{sm}
{
}

void PlayingState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
{
    world = _world;

    world->soft_reset(true);

    if (_bird == nullptr)
    {
        bird = std::make_shared<Bird>(Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
                                      Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT);
    }
    else
    {
        bird = _bird;
    }
}

void PlayingState::handle_inputs(const sf::Event& event) noexcept
{
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        switch (event.mouseButton.button)
        {
        case sf::Mouse::Left:
            bird->jump();
            break;
        default:
            break;
        }
        break;

    case sf::Event::KeyPressed:
        switch (event.key.code)
        {
        case sf::Keyboard::Space:
            bird->jump();
            break;
        case sf::Keyboard::P:
            state_machine->change_state("pause", world, bird);
        default:
            break;
        }
    default:
        break;
    }
}

void PlayingState::update(float dt) noexcept
{
    bird->update(dt);
    world->update(dt);

    if (world->collides(bird->get_collision_rect()))
    {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        state_machine->change_state("count_down", world, bird);
        return;
    }

    if (world->update_scored(bird->get_collision_rect()))
    {
        bird->inc_score(1);
        Settings::sounds["score"].play();
    }
}

void PlayingState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(bird->get_score()), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
}
