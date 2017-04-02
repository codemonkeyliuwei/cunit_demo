/*
 * UT Test file
 */
#include "math.h"               //the header file to be test
#include "CUnit/Console.h"      //Console mode
#include "CUnit/Automated.h"    //Automated mode

int InitSuite()
{
    printf("Math test init!\n");
    return 0;
}

int EndSuite()
{
    printf("Math test end\n");
    return 0;
}

//test case
void TestCaseSumIsEqual()
{
    int ret = 0;

    ret = sum(5, 10);
    CU_ASSERT_EQUAL(ret, 15);

    ret = sum(-1, 1);
    CU_ASSERT_EQUAL(ret, 0);
}

//test case
void TestCaseSumIsNotEqual()
{
    int ret = 0;

    ret = sum(5, 10);
    CU_ASSERT_EQUAL(ret, 16);   //fail

    ret = sum(-1, 1);
    CU_ASSERT_EQUAL(ret, 1);    //fail
}

// add test suit and test case
#if 0
int AddMathTest(void)
{
    CU_pSuite pSuite = NULL;

    /***********************************************
     * 1. CU_add_suite增加一个suite
     * 2. suite名字: testSuite
     * 3. InitSuite: 测试suite的初始化函数, 可为NULL
     * 4. EndSuite:  测试suite的释放函数, 可为NULL
     ***********************************************/
    pSuite = CU_add_suite("testSuite", InitSuite, EndSuite);
    if (NULL == pSuite)
    {
        printf("CU_add_suite fail!\n");
        return -1;
    }

    /***********************************************
     * 1. CU_add_suite增加一个suite
     * 2. suite名字: testSuite
     * 3. InitSuite: 测试suite的初始化函数, 可为NULL
     * 4. EndSuite:  测试suite的释放函数, 可为NULL
     ***********************************************/
    if (NULL == CU_add_test(pSuite, "TestCaseSumIsEqual", TestCaseSumIsEqual)
        || NULL == CU_add_test(pSuite, "TestCaseSumIsNotEqual", TestCaseSumIsNotEqual))
    {
        printf("Add test case fail!\n");
        return -1;
    }

    return 0;
}
#endif

int AddMathTest(void)
{
    CU_TestInfo testcases[] = {
        {"TestCaseSumIsEqual:", TestCaseSumIsEqual},
        {"TestCaseSumIsNotEqual:", TestCaseSumIsNotEqual},
        CU_TEST_INFO_NULL
    };

    CU_SuiteInfo suites[] = {
        {"Testing for math:", InitSuite, EndSuite, testcases},
        CU_SUITE_INFO_NULL
    };

    // register suite
    if(CUE_SUCCESS != CU_register_suites(suites))
    {
        printf("CU_register_suites fail!\n");
        return -1;
    }

    return 0;
}

