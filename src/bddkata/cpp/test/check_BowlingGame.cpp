#include "../src/BowlingGame.hpp"

#include <cgreen/cgreen.h>

using namespace cgreen;

Describe( BowlingGame );
BeforeEach( BowlingGame ) {}
AfterEach( BowlingGame ) {}

Ensure( BowlingGame, GutterGame ) {
    Game g;
    for (int i = 0; i < 20; i++)
    {
        g.roll(0);
    }
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
