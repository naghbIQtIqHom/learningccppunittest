#pragma once


class Game 
{
private:
    int _rolls[21];
    int _currentRoll;
public:
    Game() : _rolls {0}, _currentRoll{0} {}
    Game(const Game&)  = delete;
    Game& operator=(const Game&)  = delete;
    void roll(int pins);
    int score(void);
};
