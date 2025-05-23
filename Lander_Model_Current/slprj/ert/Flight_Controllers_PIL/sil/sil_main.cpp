/* Copyright 2020 The MathWorks, Inc.
 * MathWorks generated main function using the Target Framework */

#include <stdio.h>
#include <exception>
#include <typeinfo>

#include "xil_interface_lib.h"


int main(const int argc, char * argv[]) {

    /* Initialization code */
    /* Copyright 2019-2020 The MathWorks, Inc. */
    volatile int loop = 1; /* avoid warnings about infinite loops */
    int errorOccurred = 0;
    XIL_INTERFACE_LIB_ERROR_CODE errorCode = XIL_INTERFACE_LIB_SUCCESS;
    int terminateOnError = 1;
    


    /* Main application body */
    /* Copyright 2022 The MathWorks, Inc. */
    /* XIL initialization */    
    errorCode = xilInit(argc, (void **) argv);
    errorOccurred = (errorCode != XIL_INTERFACE_LIB_SUCCESS);
    
    /* main XIL loop */
    while(loop && !errorOccurred) {
        
        try
        {
            errorCode = xilRun();
        }
        catch(const std::exception &e){
            const std::type_info &i=typeid(e);
            xilExceptionHandler(e.what(),i.name());
            errorCode = XIL_INTERFACE_LIB_TERMINATE;
        }
        catch (...)
        {   
            xilExceptionHandler("","");
            errorCode = XIL_INTERFACE_LIB_TERMINATE;
        }
    
        errorOccurred = (errorCode != XIL_INTERFACE_LIB_SUCCESS);
        
        if (errorCode == XIL_INTERFACE_LIB_TERMINATE) {
            /* orderly shutdown of rtiostream */    
            errorCode = xilTerminateComms();   
            errorOccurred = (errorCode != XIL_INTERFACE_LIB_SUCCESS);
            break;
        }
    }
    
    

    /* Termination code */

    /* trap error with infinite loop */
    while (!terminateOnError && errorOccurred) {
    }   
    
    return errorCode;
}
