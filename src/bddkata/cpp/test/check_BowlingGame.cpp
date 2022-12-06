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
}
