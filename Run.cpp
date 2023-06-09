#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include "ValidatorIp.h" 
#include "Valid.h"



void callValidator()
{
    ValidatorIP obl;
    ValidatorIP* ptrCheck = &obl;
 
    char ip1[] = "128.0.0.1";
    char ip2[] = "125.16.100.1";
    char ip3[] = "125.512.100.1";
    char ip4[] = "125.512.100.abc";
    
   
    std::cout << ptrCheck->isValidIp(ip1) << '\n';
    std::cout << ptrCheck->isValidIp(ip2) << '\n';
    std::cout << ptrCheck->isValidIp(ip3) << '\n';
    std::cout << ptrCheck->isValidIp(ip4) << '\n';

}





