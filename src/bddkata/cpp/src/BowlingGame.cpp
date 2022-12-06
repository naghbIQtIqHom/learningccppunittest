#include "BowlingGame.hpp"

void Game::roll(int pins)
{
    _score += pins;
}

int Game::score(void)
{
    return _score;
}
