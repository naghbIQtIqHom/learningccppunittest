#include "../src/LifeGame.hpp"

#include <cgreen/cgreen.h>

using namespace cgreen;

Describe( LifeGame );
BeforeEach( LifeGame ) {}
AfterEach( LifeGame ) {}

Ensure( LifeGame, dummy ) {
    assert_that(1, is_equal_to(0));
}
