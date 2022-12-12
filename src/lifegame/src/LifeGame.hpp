#pragma once

#include <cstddef>
#include <vector>

struct GenerateCell
{
    virtual void init(size_t width, size_t height, std::vector<bool>& grid) = 0;
};

class GenCells : public GenerateCell
{
public:
    void init(size_t width, size_t height, std::vector<bool>& grid) override;
};

class Neighbor
{
private:
    std::vector<bool> grid;
    size_t cols;
    size_t rows;
public:
    Neighbor() = delete;
    Neighbor(size_t width, size_t height, std::vector<bool>& grd) : cols(width), rows(height), grid(grd) {}
    int neighbor(int x, int y);
    int neighbor_00(int x, int y);
};


class Field
{
private:
    size_t _width;
    size_t _height;
    std::vector<bool>& _field;
public:
    Field() = delete;
    Field(size_t width, size_t height, std::vector<bool>& field) : _width(width), _height(height), _field(field) {}
    //bool& cell(int x, int y);
};

class Pattern
{
protected:
    std::vector<std::vector<bool>> pattern;
public:
    Pattern() = delete;
    Pattern(std::vector<std::vector<bool>> ptn) : pattern(ptn) {}
    std::vector<bool> place(size_t width, size_t height, std::vector<bool> field, int x, int y);
};


class LifeGame
{
private:
    std::vector<bool> grid;
    size_t cols;
    size_t rows;
    GenerateCell* gencel;
public:
    LifeGame() = delete;
    LifeGame(size_t width, size_t height, GenerateCell* gen = new GenCells()) : cols(width), rows(height), grid (width*height, false), gencel(gen) {};
    std::vector<bool>& current();
    void init();
    void init2();
    void next_generation();
    size_t count_life();
};

class Option
{
public:
    enum class Seed {
        random,
        given
    };
private:
    size_t _width;
    size_t _height;
    Seed _seed;
    size_t atoi(const char* str) const;
    Seed parseKind(const char* str);
public:
    Option() = delete;
    Option(int argc, char* argv[]);
    size_t Width() { return _width; }
    size_t Height() { return _height; }
    Seed Initial() { return _seed; }
};

