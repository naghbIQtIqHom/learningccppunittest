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
        if (isStrike(frameIndex))
        {
            score += 10 + strikeBonus(frameIndex);
            frameIndex++;
        } 
        else if (isSpare(frameIndex))
        {
            score += 10 + spareBonus(frameIndex);
            frameIndex += 2;
        } else {
            score += sumOfBallsInFrame(frameIndex);
            frameIndex += 2;
        }
    }
    return score;
}

int Game::sumOfBallsInFrame(int frameIndex) 
{
    return _rolls[frameIndex] + _rolls[frameIndex + 1];
}

int Game::spareBonus(int frameIndex)
{
    return _rolls[frameIndex + 2];
}

int Game::strikeBonus(int frameIndex)
{
    return _rolls[frameIndex + 1] + _rolls[frameIndex + 2];
}

bool Game::isStrike(int frameIndex)
{
    return _rolls[frameIndex] == 10;
}

bool Game::isSpare(int frameIndex)
{
    return (_rolls[frameIndex] + _rolls[frameIndex + 1] == 10);
}
