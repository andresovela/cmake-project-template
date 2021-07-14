
#include "example1.h"
#include "unity.h"

void setUp(void) {
    // Nothing to set up
}

void tearDown(void) {
    // Nothing to clean up
}

void test_example_one_plus_one(void) {
    // 1 + 1 = 2
    TEST_ASSERT_EQUAL(2, number_plus_one(1));
}
