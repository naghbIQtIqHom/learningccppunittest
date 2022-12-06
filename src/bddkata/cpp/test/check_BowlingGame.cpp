#include "../src/BowlingGame.hpp"

#include <cgreen/cgreen.h>

using namespace cgreen;

Describe( BowlingGame );
BeforeEach( BowlingGame ) {}
AfterEach( BowlingGame ) {}


void rollMany(int n, int pins)
{
    for (int i = 0; i < n; i++)
    {
        g.roll(pins);
    }
}

Ensure( BowlingGame, GutterGame ) {
    Game g;
    int n = 20;
    int pins = 0;
    rollMany(n, pins);
    assert_that(g.score(), is_equal_to(0));
}

Ensure( BowlingGame, AllOnes ) {
    Game g;
    for (int i = 0; i < 20; i++)
    {
        g.roll(1);
    }
    assert_that(g.score(), is_equal_to(20));
}
