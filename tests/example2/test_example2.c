
#include "example2.h"
#include "unity.h"

void setUp(void) {
    // Nothing to set up
}

void tearDown(void) {
    // Nothing to clean up
}

void test_example_two_plus_two(void) {
    // 2 + 2 = 4
    TEST_ASSERT_EQUAL(4, number_plus_two(2));
}
