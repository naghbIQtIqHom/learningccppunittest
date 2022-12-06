#pragma once


class Game 
{
private:
    int _score;
public:
    Game() : _score {0} {}
    void roll(int pins);
    int score(void);
};
