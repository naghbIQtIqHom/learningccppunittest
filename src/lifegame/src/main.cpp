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

extern int main2(int argc, char* argv[]);
extern int main3(void);
int main(int argc, char* argv[])
{
    return main2(argc, argv);
}


int main4(void)
{
    const int max_generation = 1000;
    const size_t h = 79;
    const size_t v = 24;
    LifeGame g(h, v); // x, y のセルの広さを定義する
    g.init2(); // x,y にランダムにセルをばらまく
    int generation = 0;
    do {
        g.next_generation(); // 次世代セルを計算する
        display(h, v, g.current());
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    } while (g.count_life() != 0 || generation++ < max_generation);
    return 0;
}





int main2(int argc, char* argv[])
{
    Option opt(argc, argv);
    int max_generation = 1000;
    size_t h = opt.Width();
    size_t v = opt.Height();

    std::cout << h << "," << v << std::endl;
    
    LifeGame g(h, v); // x, y のセルの広さを定義する

    if (opt.Initial() == Option::Seed::given) {
        g.init2();
    } else {
        g.init(); // x,y にランダムにセルをばらまく
    }
    int generation = 0;
    do {
        g.next_generation(); // 次世代セルを計算する
        display(h, v, g.current());
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    } while (g.count_life() != 0 || generation++ < max_generation);
    return 0;
}


enum class Life {
    dead = 0,
    alive = 1
};

int next_generation(size_t width, size_t height, std::vector<Life>& field);

int next_generation(size_t width, size_t height, std::vector<Life>& field)
{
    std::vector<Life> grid = field;
    for(int i = 0; i < width * height; i += 3) {
        grid[i] = Life::alive;
    }
    return 0;
}

int main3(void)
{
    std::cout << "main3" << std::endl;
    const size_t width = 12;
    const size_t height = 3;
    std::vector<Life> grid(width*height, Life::dead);
    int count = next_generation(width, height, grid);
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            std::cout << (grid[y*width + x] == Life::alive ? "*" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}
