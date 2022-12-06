#pragma once


class Game 
{
private:
    int _rolls[21];
    int _currentRoll;
    bool isSpare(int frameIndex);
    bool isStrike(int frameIndex);
    int sumOfBallsInFrame(int frameIndex) ;
    int spareBonus(int frameIndex);
    int strikeBonus(int frameIndex);
public:
    Game() : _rolls {0}, _currentRoll{0} {}
    Game(const Game&)  = delete;
    Game& operator=(const Game&)  = delete;
    void roll(int pins);
    int score(void);
};
