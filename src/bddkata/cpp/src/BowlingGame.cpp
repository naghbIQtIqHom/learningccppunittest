#include "BowlingGame.hpp"

void Game::roll(int pins)
{
    _rolls[_currentRoll++] = pins;
}

int Game::score(void)
{
    int score = 0;
    int i = 0;
    for (int frame = 0; frame < 10; frame++)
    {
        if (_rolls[i] + _rolls[i + 1] == 10) // spare
        {
            score += 10 + _rolls[i + 2];
            i += 2;
        } else {
            score += _rolls[i] + _rolls[i + 1];
            i += 2;
        }
    }
    return score;
}
