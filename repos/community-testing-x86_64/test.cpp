#include <miopen/miopen.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    miopenHandle_t handle;
    miopenStatus_t s = miopenCreate(&handle);

    if(s != miopenStatusSuccess){
        printf("Cannot create handle for MIOpen!\n");
        return EXIT_FAILURE;
    }
    miopenDestroy(handle);
    printf("TESTS PASSED!\n");
}
