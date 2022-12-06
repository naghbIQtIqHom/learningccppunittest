#pragma once


class Game 
{
private:
    int _score;
public:
    Game() : _score {0} {}
    Game(const Game&)  = delete;
    Game& operator=(const Game&)  = delete;
    void roll(int pins);
    int score(void);
};
