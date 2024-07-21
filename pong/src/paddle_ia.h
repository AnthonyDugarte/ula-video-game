/*
    ISPPJ1 2024
    Study Case: Pong

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of a pong paddle and the declaration
    of the functions to init it, update it, and render it.
*/

#pragma once

#include "ball.h"
#include "paddle.h"

void update_paddle_ia(struct Paddle *, struct Ball *);
