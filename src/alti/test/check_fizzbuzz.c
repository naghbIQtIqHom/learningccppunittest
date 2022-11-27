#include <cgreen/cgreen.h>
#include <cgreen/mocks.h>
#include <stdio.h>

#include "fizzbuzz.h"

Describe( FizzBuzz );
BeforeEach( FizzBuzz ) {}
AfterEach( FizzBuzz ) {}

Ensure( FizzBuzz, returning_number_case ) {
    char actual[10] = {0};
    fizzbuzz(1, actual);
    assert_that( actual, is_equal_to_string("1") );
}

Ensure( FizzBuzz, returning_fizz_when_multiplied_number_by_three ) {
    char actual[10] = {0};
    fizzbuzz(3, actual);
    assert_that( actual, is_equal_to_string("fizz") );
}

Ensure( FizzBuzz, returning_fizz_when_multiplied_number_by_five ) {
    char actual[10] = {0};
    fizzbuzz(5, actual);
    assert_that( actual, is_equal_to_string("buzz") );
}

Ensure( FizzBuzz, returning_fizz_when_multiplied_number_by_three_and_five ) {
    char actual[10] = {0};
    fizzbuzz(15, actual);
    assert_that( actual, is_equal_to_string("fizzbuzz") );
}
