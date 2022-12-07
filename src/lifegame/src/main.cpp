#include "LifeGame.hpp"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

void display(size_t width, size_t height, std::vector<bool> grid)
{
    std::cout<< u8"\033[2J\033[1;1H";
    for(size_t y = 0; y < height; y++) {
        for(size_t x = 0; x < width; x++) {
            std::cout << ( grid[x + y * width] ? "*" : " " );
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    LifeGame g(79, 24); // x, y のセルの広さを定義する
    g.init(); // x,y にランダムにセルをばらまく
    for(int generation = 0; generation < 10; generation++) {
        std::vector<bool> grid = g.current(); // 現状のセルの状態を配列に書き込む
        display(79, 24, grid);
        g.next_generation(); // 次世代セルを計算する
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
