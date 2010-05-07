/* 
 * File:   main.cpp
 * Author: aidas
 *
 * Created on May 2, 2010, 11:11 PM
 */

#include <stdlib.h>
#include <iostream>
#include "word.h"
#include "vm.h"
/*
 * 
 */

#include <iostream>
#include <fstream>

int main(int argc, char** argv) {

    vm v;
    v.setmemoryfromfile("sample.prg");

    while (v.finished() == false ){
        v.step();
    }

    //    std::string s;
    //    std::cin >> s;
    //    word w("ch", s);
    //    int a = w.value;
    //    std::cout << w.value << std::endl << w.vchar() << std::endl;
    //    w.value = a;
    //    std::cout << w.value << std::endl << w.vchar() << std::endl;




    //std::cout << " "<< m.hexadimal() <<" " << a.vchar();
    return (EXIT_SUCCESS);
}

