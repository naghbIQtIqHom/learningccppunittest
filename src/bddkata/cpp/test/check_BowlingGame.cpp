#include "../src/BowlingGame.hpp"

#include <cgreen/cgreen.h>

using namespace cgreen;

Describe( BowlingGame );
BeforeEach( BowlingGame ) {}
AfterEach( BowlingGame ) {}


void rollMany(Game& g, int n, int pins)
{
    for (int i = 0; i < n; i++)
    {
        g.roll(pins);
    }
}

Ensure( BowlingGame, GutterGame ) {
    Game g;
    rollMany(g, 20, 0);
    assert_that(g.score(), is_equal_to(0));
}

Ensure( BowlingGame, AllOnes ) {
    Game g;
    rollMany(g, 20, 1);
    assert_that(g.score(), is_equal_to(20));
}

void rollSpare(Game& g)
{
    g.roll(5);
    g.roll(5);
}

Ensure( BowlingGame, OneSpare ) {
    Game g;
    rollSpare(g);
    g.roll(3);
    rollMany(g, 17, 0);
    assert_that(g.score(), is_equal_to(16));
}

void rollStrike(Game& g)
{
    g.roll(10);
}

Ensure( BowlingGame, OneStrike ) {
    Game g;
    rollStrike(g);
    g.roll(3);
    g.roll(4);
    rollMany(g, 16, 0);
    assert_that(g.score(), is_equal_to(24));
}

Ensure( BowlingGame, PerfectGame ) {
    Game g;
    rollMany(g, 12, 10);
    assert_that(g.score(), is_equal_to(300));
}
