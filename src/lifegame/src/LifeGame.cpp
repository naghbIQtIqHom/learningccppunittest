#include <string>
#include <random>
#include <iostream>
#include <numeric>
#include "LifeGame.hpp"

std::vector<bool>& LifeGame::current()
{
    return grid;
}

void LifeGame::init()
{
#if true
    gencel->init(cols, rows, grid);
#else
    grid[0] = false;
    grid[1] = true;
    grid[2] = false;
#endif
}

void LifeGame::init2()
{
    // block
    grid[10*cols + 20 + 0] = true;
    grid[10*cols + 20 + 1] = true;
    grid[11*cols + 20 + 0] = true;
    grid[11*cols + 20 + 1] = true;
    
    // blinker
    grid[2*cols + 0] = true;
    grid[2*cols + 1] = true;
    grid[2*cols + 2] = true;

    // beacon
    grid[5*cols + 10 + 0] = true;
    grid[5*cols + 10 + 1] = true;
    grid[6*cols + 10 + 0] = true;
    grid[6*cols + 10 + 1] = true;
    grid[7*cols + 12 + 0] = true;
    grid[7*cols + 12 + 1] = true;
    grid[8*cols + 12 + 0] = true;
    grid[8*cols + 12 + 1] = true;

    // glider
    grid[20*cols + 23 + 0] = true;
    grid[20*cols + 23 + 1] = true;
    grid[20*cols + 23 + 2] = true;
    grid[21*cols + 23 + 0] = true;
    grid[22*cols + 23 + 1] = true;


    // breeder
    grid[17*cols + 30 + 1] = true;
    grid[17*cols + 30 + 3] = true;
    grid[16*cols + 30 + 3] = true;
    grid[15*cols + 30 + 5] = true;
    grid[14*cols + 30 + 5] = true;
    grid[13*cols + 30 + 5] = true;
    grid[14*cols + 30 + 7] = true;
    grid[13*cols + 30 + 7] = true;
    grid[12*cols + 30 + 7] = true;
    grid[13*cols + 30 + 8] = true;

    // bar
    grid[15*cols + 6 + 1] = true;
    grid[15*cols + 6 + 2] = true;
    grid[15*cols + 6 + 3] = true;
    grid[15*cols + 6 + 4] = true;
    grid[15*cols + 6 + 5] = true;
    grid[15*cols + 6 + 6] = true;
    grid[16*cols + 6 + 1] = true;
    grid[16*cols + 6 + 2] = true;
    grid[16*cols + 6 + 3] = true;
    grid[16*cols + 6 + 4] = true;
    grid[16*cols + 6 + 5] = true;
    grid[16*cols + 6 + 6] = true;

    // galaxy
    grid[ 5*cols + 60 + 1] = true;
    grid[ 5*cols + 60 + 2] = true;
    grid[ 5*cols + 60 + 3] = true;
    grid[ 5*cols + 60 + 4] = true;
    grid[ 5*cols + 60 + 5] = true;
    grid[ 5*cols + 60 + 6] = true;
    grid[ 6*cols + 60 + 1] = true;
    grid[ 6*cols + 60 + 2] = true;
    grid[ 6*cols + 60 + 3] = true;
    grid[ 6*cols + 60 + 4] = true;
    grid[ 6*cols + 60 + 5] = true;
    grid[ 6*cols + 60 + 6] = true;

    grid[12*cols + 63 + 1] = true;
    grid[12*cols + 63 + 2] = true;
    grid[12*cols + 63 + 3] = true;
    grid[12*cols + 63 + 4] = true;
    grid[12*cols + 63 + 5] = true;
    grid[12*cols + 63 + 6] = true;
    grid[13*cols + 63 + 1] = true;
    grid[13*cols + 63 + 2] = true;
    grid[13*cols + 63 + 3] = true;
    grid[13*cols + 63 + 4] = true;
    grid[13*cols + 63 + 5] = true;
    grid[13*cols + 63 + 6] = true;


    grid[ 8*cols + 60 + 1] = true;
    grid[ 9*cols + 60 + 1] = true;
    grid[10*cols + 60 + 1] = true;
    grid[11*cols + 60 + 1] = true;
    grid[12*cols + 60 + 1] = true;
    grid[13*cols + 60 + 1] = true;
    grid[ 8*cols + 60 + 2] = true;
    grid[ 9*cols + 60 + 2] = true;
    grid[10*cols + 60 + 2] = true;
    grid[11*cols + 60 + 2] = true;
    grid[12*cols + 60 + 2] = true;
    grid[13*cols + 60 + 2] = true;

    grid[ 5*cols + 67 + 1] = true;
    grid[ 6*cols + 67 + 1] = true;
    grid[ 7*cols + 67 + 1] = true;
    grid[ 8*cols + 67 + 1] = true;
    grid[ 9*cols + 67 + 1] = true;
    grid[10*cols + 67 + 1] = true;
    grid[ 5*cols + 67 + 2] = true;
    grid[ 6*cols + 67 + 2] = true;
    grid[ 7*cols + 67 + 2] = true;
    grid[ 8*cols + 67 + 2] = true;
    grid[ 9*cols + 67 + 2] = true;
    grid[10*cols + 67 + 2] = true;

}

void GenCells::init(size_t width, size_t height, std::vector<bool>& grid)
{
    //std::mt19937 rand_src(123);
    std::random_device rand_src;
    std::uniform_int_distribution<int> rand_dist(0, 10);
    for(size_t x = 0; x < width; x++) {
        for(size_t y = 0; y < height; y++) {
            if (rand_dist(rand_src) < 3) {
                grid[x + y * width] = true;
            } else {
                grid[x + y * width] = false;
            }
        }
    }
}

void LifeGame::next_generation()
{
    Neighbor nbr(cols, rows, grid);
    std::vector<bool> new_generation = grid;
    for(size_t y = 0; y < rows; y++) {
        for(size_t x = 0; x < cols; x++) {
            size_t living_n = nbr.neighbor(x, y);
            if (grid[y*cols+x] == false) {
                if (living_n == 3) {
                    new_generation[y*cols + x] = true;
                }
            } else {
                if (living_n <= 1) {
                    new_generation[y*cols + x] = false;
                } else if (living_n <= 3) {
                    new_generation[y*cols + x] = true;
                } else {
                    new_generation[y*cols + x] = false;
                }
            }
        }
    }
    grid.swap(new_generation);
}

size_t LifeGame::count_life()
{
    return std::accumulate(grid.begin(), grid.end(), 0, [](int acc, bool i) { return acc + (i ? 1 : 0); });
}

int Neighbor::neighbor(int x, int y)
{
    int n = neighbor_00(x, y);
    if (n != -1) {
        return n;
    }
    return 0
        + (grid[(y-1)*cols + x - 1 ] ? 1 : 0 )
        + (grid[(y-1)*cols + x     ] ? 1 : 0 )
        + (grid[(y-1)*cols + x + 1 ] ? 1 : 0 )
        + (grid[y*cols     + x - 1 ] ? 1 : 0 )
        //+ (grid[y*cols     + x     ] ? 1 : 0 )
        + (grid[y*cols     + x + 1 ] ? 1 : 0 )
        + (grid[(y+1)*cols + x - 1 ] ? 1 : 0 )
        + (grid[(y+1)*cols + x     ] ? 1 : 0 )
        + (grid[(y+1)*cols + x + 1 ] ? 1 : 0 );
   
}

int Neighbor::neighbor_00(int x, int y)
{
    if ( x == 0 && y == 0 ) {
        return 0
            + (grid[y*cols     + x + 1 ] ? 1 : 0 )
            + (grid[(y+1)*cols + x     ] ? 1 : 0 )
            + (grid[(y+1)*cols + x + 1 ] ? 1 : 0 );
    } else if ( x == (cols -1)  && y == 0 ) { // 右上
        return 0
            + (grid[y*cols     + x - 1 ] ? 1 : 0 )
            + (grid[(y+1)*cols + x - 1 ] ? 1 : 0 )
            + (grid[(y+1)*cols + x     ] ? 1 : 0 );
    } else if ( x == (cols -1)  && y == (cols -1) ) { // 右下
        return 0
            + (grid[(y-1)*cols + x - 1 ] ? 1 : 0 )
            + (grid[(y-1)*cols + x     ] ? 1 : 0 )
            + (grid[y*cols     + x - 1 ] ? 1 : 0 );
    } else if ( x == 0  && y == (cols -1) ) { // 左下
        return 0
            + (grid[(y-1)*cols + x     ] ? 1 : 0 )
            + (grid[(y-1)*cols + x + 1 ] ? 1 : 0 )
            + (grid[y*cols     + x + 1 ] ? 1 : 0 );
    } else if ( y == 0 ) { // 上辺
        return 0
            + (grid[y*cols     + x - 1 ] ? 1 : 0 )
            + (grid[y*cols     + x + 1 ] ? 1 : 0 )
            + (grid[(y+1)*cols + x - 1 ] ? 1 : 0 )
            + (grid[(y+1)*cols + x     ] ? 1 : 0 )
            + (grid[(y+1)*cols + x + 1 ] ? 1 : 0 );
    } else if ( x == 0 ) { // 左辺
        return 0
            + (grid[(y-1)*cols + x     ] ? 1 : 0 )
            + (grid[(y-1)*cols + x + 1 ] ? 1 : 0 )
            + (grid[y*cols     + x - 1 ] ? 1 : 0 )
            + (grid[y*cols     + x + 1 ] ? 1 : 0 )
            + (grid[(y+1)*cols + x     ] ? 1 : 0 )
            + (grid[(y+1)*cols + x + 1 ] ? 1 : 0 );
    } else if ( x == (cols -1) ) { // 右辺
        return 0
            + (grid[(y-1)*cols + x - 1 ] ? 1 : 0 )
            + (grid[(y-1)*cols + x     ] ? 1 : 0 )
            + (grid[y*cols     + x - 1 ] ? 1 : 0 )
            + (grid[(y+1)*cols + x - 1 ] ? 1 : 0 )
            + (grid[(y+1)*cols + x     ] ? 1 : 0 );
    } else if ( y == (cols -1) ) { // 下辺
        return 0
            + (grid[(y-1)*cols + x - 1 ] ? 1 : 0 )
            + (grid[(y-1)*cols + x     ] ? 1 : 0 )
            + (grid[(y-1)*cols + x + 1 ] ? 1 : 0 )
            + (grid[y*cols     + x - 1 ] ? 1 : 0 )
            + (grid[y*cols     + x + 1 ] ? 1 : 0 );
    }
    return -1;
}


size_t Option::atoi(const char* str) const
{
    try {
        return std::stoi(str);
    }
    catch (const std::invalid_argument& e) {}
    catch (const std::out_of_range& e) {}
}

Option::Seed Option::parseKind(const char* str)
{
    std::string random("random");
    std::string given("given");
    if(given.compare(str) == 0) {
        _seed = Seed::given;
    } else {
        _seed = Seed::random;
    }
}

Option::Option(int argc, char* argv[])
{
    _width = 79;
    _height = 24;
    _seed = Seed::random;
    if (argc < 2) return;
    if (argc == 2){
        parseKind(argv[1]);
        return;
    }
    _width = atoi(argv[1]);
    _height = atoi(argv[2]);
    if (argc > 3){
        parseKind(argv[3]);
    }
}

std::vector<bool> Pattern::place(size_t width, size_t height, std::vector<bool> field, int x, int y)
{
    if (x >= width || y >= height ) return field;
    for(int row = 0; row < pattern.size(); row++) {
        for(int col = 0; col < pattern[row].size(); col++) {
            field[row * (y + width) + (col + x)] = pattern[row][col];
        }
    }
    return field;
}

// bool& Field::cell(int x, int y)
// {
//     return _field[_width * y + x];
// }
