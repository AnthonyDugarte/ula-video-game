/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Bird.
*/

#include "Bird.hpp"
#include "Settings.hpp"

Bird::Bird(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, vy{0.f}, sprite{Settings::textures["bird"]}
{
    sprite.setPosition(x, y);
}

void Bird::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
    vy = 0.f;
    sprite.setPosition(x, y);
    score = 0;
}

sf::FloatRect Bird::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, width, height};
}

void Bird::jump() noexcept
{
    if (!jumping)
    {
        jumping = true;
    }
}

void Bird::update(float dt) noexcept
{
    vy += Settings::GRAVITY * dt;

    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }

    y += vy * dt;
    sprite.setPosition(x, y);
}

void Bird::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}

void Bird::inc_score(int diff = 0) noexcept
{
    score += diff;
}

const int& Bird::get_score() noexcept
{
    return score;
}
