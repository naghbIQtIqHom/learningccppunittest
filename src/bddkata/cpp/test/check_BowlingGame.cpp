#include "../src/BowlingGame.hpp"

#include <cgreen/cgreen.h>
#include <cgreen/mocks.h>

using namespace cgreen;

Describe( BowlingGame );
BeforeEach( BowlingGame ) {}
AfterEach( BowlingGame ) {}

Ensure( BowlingGame, GutterGame ) {
    Game g;
}
