#include "unity.h"
#include "unity_internals.h"
#include <fun.h>

/* Modify these two lines according to the project */
#define PROJECT_NAME    "employee_record_system"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_trial(void);

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
RUN_TEST(test_trial);

    
    /* Close the Unity Test Framework */
    return UNITY_END();
}
void test_trial(void)
{
    TEST_PASS();
}