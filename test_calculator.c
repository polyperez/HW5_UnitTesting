#include "unity.h"
#include "calculator.h"

void setUp(void) {
    //// Initialize any resources needed for your tests here
    // For example, you might reset a global value, dynamically allocate memory, etc.
    // In this example, we do not need anything here.

}

void tearDown(void) {
    //Clean up resources after each test
    //For example, free memory, reset global values etc.
    //In this example, we do not need anything
}

void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL(5, add(2,3)); //2+3 = 5
}

void test_add_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, add(5,-4)); //expect 5 + -4 = 1
}

void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-7, add(-3, -4)); //expect -3 + -4 = -7
}

//NOTE: Can do multiple validations in one test
void test_add_zero(void) {
    TEST_ASSERT_EQUAL(10,add(10,0)); //expect 10 + 0 = 10
    TEST_ASSERT_EQUAL(0, add(0,0)); //expect 0+0 = 0
}

//Checks for overflow from variable type
void test_add_overflow(void) {
    int result = add(INT_MAX, 1);  //Should wrap around or cause undefined behavior
    TEST_ASSERT_TRUE(result < 0);  //This checks if overflow occurred
}

//Checks for underflow from variable type
void test_add_underflow(void) {
    int result = add(INT_MIN, -1); 
    TEST_ASSERT_TRUE(result > 0);  //This checks if underflow occurred
}

void test_subtract(void)
{
    TEST_ASSERT_EQUAL_INT(3, subtract(5,2));
}

void test_multiply(void)
{
    TEST_ASSERT_EQUAL_INT(20, multiply(5,4));
}

void test_divide(void)
{
    TEST_ASSERT_EQUAL_INT(2, divide(10,5));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_positive_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);
    RUN_TEST(test_subtract);
    RUN_TEST(test_multiply);
    RUN_TEST(test_divide);
    return UNITY_END();
}

