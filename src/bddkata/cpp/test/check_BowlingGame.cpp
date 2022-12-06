#include "../src/BowlingGame.hpp"

#include <cgreen/cgreen.h>
#include <cgreen/mocks.h>

using namespace cgreen;

Describe( sut );
BeforeEach( sut ) {}
AfterEach( sut ) {}

Ensure( sut, test_name_1 ) {
    assert_that( 1 == 1 );
}

int main(int argc, char **argv) {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, sut, test_name_1);
    return run_test_suite(suite, create_text_reporter());
}
