#include <stdio.h>
#include "testing.h"

BEGIN_TESTS

test some_test() {
    DEF_TEST("We did it, America!");

    DO_TEST(1 == 1, "one equals one");

    END_TEST;
}

test whatever() {
    DEF_TEST("This test should fail.");

    DO_TEST(0, "something that resulted in failure");

    END_TEST;
}

int main() {
    RUN_TEST(some_test); 
    RUN_TEST(whatever);
}
