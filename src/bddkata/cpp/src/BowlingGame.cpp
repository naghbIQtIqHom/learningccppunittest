#include "BowlingGame.hpp"

void Game::roll(int pins)
{
    _score += pins;
    _rolls[_currentRoll++] = pins;
}

int Game::score(void)
{
    return _score;
}
