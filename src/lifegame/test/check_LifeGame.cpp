#include "../src/LifeGame.hpp"

#include <numeric>
#include <cgreen/cgreen.h>

using namespace cgreen;

Describe( LifeGame );
BeforeEach( LifeGame ) {}
AfterEach( LifeGame ) {}

// Ensure( LifeGame, current_returns_grid ) {
//     //LifeGame g(1, 1);
//     LifeGame g(1, 1);
//     //std::vector<bool> grid = g.current();
//     //assert_that(grid.size(), is_equal_to(0));
//     //assert_that(0, is_equal_to(0));
//     std::vector<bool> grid(1);
//     grid = { true, false, false };
//     std::vector<bool> gg = grid;
//     assert_that(gg.size(), is_equal_to(3));
// }

Ensure( LifeGame, current_returns_grid_as_given_size ) {
    LifeGame g(2, 3);
    auto grid = g.current();
    assert_that(grid.size(), is_equal_to(6));
}

class GenCellsEasyThree : public GenerateCell
{
    void init(size_t width, size_t height, std::vector<bool>& grid) override;
};

void GenCellsEasyThree::init(size_t width, size_t height, std::vector<bool>& grid)
{
    grid[0] = false;
    grid[1] = true;
    grid[2] = false;
}

Ensure( LifeGame, init_scatters_living_cells ) {
    LifeGame g(3, 1, new GenCellsEasyThree());
    g.init();
    auto grid = g.current();
    {
        bool actual = grid[0];
        assert_that(actual, is_equal_to(false));
    }
    {
        bool actual = grid[1];
        assert_that(actual, is_equal_to(true));
    }    
    {
        bool actual = grid[2];
        assert_that(actual, is_equal_to(false));
    }    
}

class GenCellsStub : public GenerateCell
{
private:
    std::vector<bool> field;
public:
    GenCellsStub() = delete;
    GenCellsStub(std::vector<bool>& grid) : field(grid) {}
    void init(size_t width, size_t height, std::vector<bool>& grid) override;
};

void GenCellsStub::init(size_t width, size_t height, std::vector<bool>& grid)
{
    grid = field;
}

Ensure( LifeGame, next_generation_provides_next_generation_given_neighbor_has_0_cell ) {
    std::vector<bool> expected = {
        false, false, false,
        false, false, false,
        false, false, false };
    std::vector<bool> field = {
        false, false, false,
        false, false, false,
        false, false, false };
    LifeGame g(3, 1, new GenCellsStub(field));
    g.init();
    g.next_generation();
    auto grid = g.current();
    for(int i = 0; i < grid.size(); i++) {
        bool actual = grid[i];
        bool expect = expected[i];
        assert_that(actual, is_equal_to(expect));
    }
}

Ensure( LifeGame, next_generation_provides_next_generation_given_neighbor_has_1_cell ) {
    std::vector<bool> expected = {
        false, false, false,
        false, false, false,
        false, false, false };
    std::vector<bool> field = {
        true,  false, false,
        false, true,  false,
        false, false, false };
    LifeGame g(3, 3, new GenCellsStub(field));
    g.init();
    g.next_generation();
    auto grid = g.current();
    for(int i = 0; i < grid.size(); i++) {
        bool actual = grid[i];
        bool expect = expected[i];
        assert_that(actual, is_equal_to(expect));
    }
}

Ensure( LifeGame, next_generation_is_born_given_neighbor_has_3_cell ) {
    std::vector<bool> expected = {
        false, false, false,
        false, true, false,
        false, false, false };
    std::vector<bool> field = {
        true,  false, true,
        false, false, false,
        false, true,  false };
    LifeGame g(3, 3, new GenCellsStub(field));
    g.init();
    g.next_generation();
    auto grid = g.current();
    for(int i = 0; i < grid.size(); i++) {
        bool actual = grid[i];
        bool expect = expected[i];
        assert_that(actual, is_equal_to(expect));
    }
}

Ensure( LifeGame, blinker ) {
    std::vector<bool> expected1 = {
        false, false, false, false, false,
        false, false, true,  false, false,
        false, false, true,  false, false,
        false, false, true,  false, false,
        false, false, false, false, false };
    std::vector<bool> expected2 = {
        false, false, false, false, false,
        false, false, false, false, false,
        false, true,  true,  true,  false,
        false, false, false, false, false,
        false, false, false, false, false };
    std::vector<bool> field = {
        false, false, false, false, false,
        false, false, false, false, false,
        false, true,  true,  true,  false,
        false, false, false, false, false,
        false, false, false, false, false };
    LifeGame g(5, 5, new GenCellsStub(field));
    g.init();
    {
        g.next_generation();
        auto grid = g.current();
        for(int i = 0; i < grid.size(); i++) {
            bool actual = grid[i];
            bool expect = expected1[i];
            assert_that(actual, is_equal_to(expect));
        }
    }
    {
        g.next_generation();
        auto grid = g.current();
        for(int i = 0; i < grid.size(); i++) {
            bool actual = grid[i];
            bool expect = expected2[i];
            assert_that(actual, is_equal_to(expect));
        }
    }
}


