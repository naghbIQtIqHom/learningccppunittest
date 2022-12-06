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
        score += _rolls[i] + _rolls[i+1];
        i += 2;
    }
    return score;
}
