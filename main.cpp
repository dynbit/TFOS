/* 
 * File:   main.cpp
 * Author: aidas
 *
 * Created on May 2, 2010, 11:11 PM
 */

#include <stdlib.h>
#include <iostream>
#include "word.h"
#include "virtualstack.h"
/*
 * 
 */
int main(int argc, char** argv) {


    word a("16", "FFFFFFFF");
    word m("10", "-18");
    word c("ch", "ABCD");

    int i;
    std::string k;
    k="ABCD";
    i=k[0];
    std::cout << " "<< m.hexadimal() <<" " << a.vchar();
    return (EXIT_SUCCESS);
}

