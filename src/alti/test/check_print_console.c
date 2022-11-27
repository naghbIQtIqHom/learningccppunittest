#include <cgreen/cgreen.h>
#include <cgreen/mocks.h>
#include <stdio.h>

#include "fizzbuzz.h"

#ifdef BUILD_TEST
extern char messages[5][10];
extern int message_index;

Describe( Write_Console );
BeforeEach( Write_Console ) {}
AfterEach( Write_Console ) {}

Ensure( Write_Console, returning_number_case ) {
    write_console(5, fizzbuzz);
    assert_that( messages[0], is_equal_to_string("1 : 1\n") );
    assert_that( messages[1], is_equal_to_string("2 : 2\n") );
    assert_that( messages[2], is_equal_to_string("3 : fizz\n") );
    assert_that( messages[3], is_equal_to_string("4 : 4\n") );
    assert_that( messages[4], is_equal_to_string("5 : buzz\n") );
}
#endif
