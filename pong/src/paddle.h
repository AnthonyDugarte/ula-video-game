/*
    ISPPJ1 2024
    Study Case: Pong

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of a pong paddle and the declaration
    of the functions to init it, update it, and render it.
*/

#pragma once

#include <hitbox.h>

struct Paddle {
  float x;
  float y;
  float width;
  float height;
  float vy;

  int ia_controlled;
};

void init_paddle(struct Paddle *paddle, float x, float y, float w, float h, int ia_controlled);

void build_paddle_hitbox(struct Paddle paddle, struct Hitbox *hitbox);

void update_paddle(struct Paddle *paddle, float dt);

void render_paddle(struct Paddle paddle);
