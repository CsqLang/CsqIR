#if !defined(ERROR_IR)
#define ERROR_IR

#include "lexer.h"

void error(string error_){
    printf("Error : %s\n", error_.c_str());
}

#endif // ERROR_IR
