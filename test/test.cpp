#include <Arduino.h>
#include <unity.h>

void test(void) {
    TEST_ASSERT_EQUAL(0, 0);
}

void process() {
    UNITY_BEGIN();
    RUN_TEST(test);
    UNITY_END();
}

void setup() {
    delay(2000);
    process();
}

void loop() {
    delay(1000);
}
