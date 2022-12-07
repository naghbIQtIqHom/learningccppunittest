#include "../src/LifeGame.hpp"

#include <cgreen/cgreen.h>

using namespace cgreen;

Describe( LifeGame );
BeforeEach( LifeGame ) {}
AfterEach( LifeGame ) {}

Ensure( LifeGame, current_returns_grid ) {
    LifeGame g(1, 1);
    std::vector<bool> grid = g.current();
}

