#include "BowlingGame.hpp"

void Game::roll(int pins)
{
    _rolls[_currentRoll++] = pins;
}

int Game::score(void)
{
    int score = 0;
    for (int i = 0; i < sizeof(_rolls)/sizeof(*_rolls); i++)
    {
        if (_rools[i] + _rolls[i+1] == 10)
        {
            score +=
        }
        score += _rolls[i];
    }
    return score;
}
