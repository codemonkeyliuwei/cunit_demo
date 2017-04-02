/*
 * main for ut test
 */

#include <assert.h>
#include "CUnit/Console.h"      //Console mode
#include "CUnit/Automated.h"    //Automated mode

extern int AddMathTest(void);

int main(int argc, char* argv[])
{
    //��ʼ�����Ե�Ԫ
    if( CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    //��ȡ���Ե�Ԫ, ȷ����ʼ���ɹ�
    assert(NULL != CU_get_registry());

    //����Ƿ���ִ��
    assert(!CU_is_test_running());

    //��Ӳ�������  
    if (0 != AddMathTest())
    {
        CU_cleanup_registry();
        return CU_get_error(); 
    }

    #ifdef CUNIT_CONSOLE
    //consoleģʽִ������
    CU_console_run_tests();
    #endif

    #ifdef CUNIT_AUTOMATED
    //automatedģʽִ������
    CU_set_output_filename("MathTest");
    CU_list_tests_to_file(); 
    CU_automated_run_tests();
    #endif

    CU_cleanup_registry();

    return 0;
}

