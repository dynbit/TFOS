/* 
 * File:   main.cpp
 * Author: aidas
 *
 * Created on May 2, 2010, 11:11 PM
 */

#include "gui.h"

int main(int argc, char** argv) {

	GUI * realGUI;
	realGUI = new GUI(argc, argv);
	realGUI->start();

    /*realmachine * real;
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


    //std::cout << " "<< m.hexadimal() <<" " << a.vchar();*/
    
    
    return 0;
}

