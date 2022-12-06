#include "BowlingGame.hpp"

void Game::roll(int pins)
{
    _score += pins;
    _rolls[_currentRoll++] = pins;
}

int Game::score(void)
{
    int s = 0;
    for (int i = 0; i < sizeof(_rolls)/sizeof(*_rolls); i++)
    {
        s += _rolls[i];
    }
    return s;
}
