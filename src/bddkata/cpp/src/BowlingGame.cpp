#include "BowlingGame.hpp"

void Game::roll(int pins)
{
    _rolls[_currentRoll++] = pins;
}

int Game::score(void)
{
    int score = 0;
    int frameIndex = 0;
    for (int frame = 0; frame < 10; frame++)
    {
        if (_rolls[frameIndex] + _rolls[frameIndex + 1] == 10) // spare
        {
            score += 10 + _rolls[frameIndex + 2];
            frameIndex += 2;
        } else {
            score += _rolls[frameIndex] + _rolls[frameIndex + 1];
            frameIndex += 2;
        }
    }
    return score;
}
