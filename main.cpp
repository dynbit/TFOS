/* 
 * File:   main.cpp
 * Author: aidas
 *
 * Created on May 2, 2010, 11:11 PM
 */

#include <stdlib.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include "word.h"
#include "vm.h"
#include "realmachine.h"

int main(int argc, char** argv) {


    realmachine * real;
    real = new realmachine;
    vm v(real, 0, "sample.prg");
   
    while (v.finish == false ){
        v.step();
    }

    //std::string s;
    //std::cin >> s;
    //word w("ch", s);
    //int a = w.value;
    //std::cout << w.value << std::endl << w.vchar() << std::endl;
    //w.value = a;
    //std::cout << w.value << std::endl << w.vchar() << std::endl;

    std::cout << "\n";
    std::cout << "VEIKIA\n";

    delete real;


    //std::cout << " "<< m.hexadimal() <<" " << a.vchar();
    return (EXIT_SUCCESS);
}

