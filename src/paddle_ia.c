#include "paddle_ia.h"
#include "settings.h"
#include <math.h>

void update_paddle_ia(struct Paddle *paddle, struct Ball *ball) {
  float paddle_center = paddle->y + paddle->height / 2;
  float ball_center = ball->y + ball->height / 2;

  float center_diff = paddle_center - ball_center;

  float threshold = paddle->height * 0.1f;

  float dir = center_diff > threshold ? -1 : 1;

  if (fabs(center_diff) > threshold) {
    paddle->vy = PADDLE_SPEED * dir * 0.63f;
  } else {
    paddle->vy = 0;
  }
}
