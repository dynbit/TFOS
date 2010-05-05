/* 
 * File:   vm.cpp
 * Author: aidas
 * 
 * Created on May 3, 2010, 8:01 PM
 */

#include "vm.h"
#include "word.h"
#include <sstream>
#include <iostream>
#include <cstring>
#include <iostream>
#include <fstream>

vm::vm() {
    vm::ST = 255;
    vm::IC = 96;


}

int vm::realadr(int hex) {
    return hex;
}

void vm::add() {
    memory[realadr(vm::ST - 1)] += memory[realadr(vm::ST)];
    ST -= 1;
}

void vm::sub() {
    memory[realadr(vm::ST - 1)] -= memory[realadr(vm::ST)];
    ST -= 1;
}

void vm::mul() {
    memory[realadr(vm::ST - 1)] *= memory[realadr(vm::ST)];
    ST -= 1;
}

void vm::div() {
    memory[realadr(vm::ST - 1)] /= memory[realadr(vm::ST)];
    ST -= 1;
}

void vm::pdch() {
    int i = memory[realadr(vm::ST)];
    std::string s;
    std::stringstream out;
    out << i;
    s = out.str();

    word a("10", s);
    std::cout << a.vchar();
}

void vm::pdnb() {
    std::cout << memory[realadr(vm::ST)];
}

void vm::gdch() {
    std::string x, y;
    vm::ST += 1;
    std::getline(std::cin, y);
    x = "    ";
    x[0] = y[0];
    x[1] = y[1];
    x[2] = y[2];
    x[3] = y[3];
    word a("ch", x);
    memory[realadr(vm::ST)] = a.value;
}

void vm::gdnb() {
    int x;
    vm::ST += 1;
    std::cin >> x;
    memory[realadr(vm::ST)] = x;
}

void vm::ps(int hex) {
    vm::ST++;
    memory[realadr(vm::ST)] = memory[realadr(hex)];
}

void vm::pp(int hex) {
    memory[realadr(hex)] = memory[realadr(vm::ST)];
    vm::ST--;
}

void vm::je(short adr) {
    if (memory[realadr(vm::ST)] == 0) {
        vm::IC = adr;
    }
}

void vm::jn(short adr) {
    if (memory[realadr(vm::ST)] != 0) {
        vm::IC = adr;
    }

}

void vm::jm(short adr) {
    vm::IC = adr;
}

void vm::halt() {
    std::cout << "\nVM HALT\n";
}

void vm::setmemoryfromfile(std::string filename) {
    std::string s;
    std::ifstream file(filename.c_str());
    word conv("10", "0");
    short mempnt = 0;
    file >> s;
    if (s == "DATA") {
        while (file >> s && s != "CODE" && mempnt < 96) {
            if (s == "DE") {
                vm::memory[realadr(mempnt)] = 0;
                mempnt += 1;
            } else if (s == "DW") {
                file >> s;
                conv.renew("10", s);
                vm::memory[realadr(mempnt)] = conv.value;
                mempnt += 1;

         //       std::cout << conv.vchar() << std::endl; //debug
            } else if (s == "DB") {
                file >> s;
                conv.renew("ch", s);
                vm::memory[realadr(mempnt)] = conv.value;
                mempnt += 1;

          //      std::cout << conv.vchar() << std::endl; //debug
            }
        }
        mempnt = 96;
        while (file >> s && s != "HALT" && mempnt < 192) {
            conv.renew("ch", s);
            vm::memory[realadr(mempnt)] = conv.value;
            mempnt += 1;
        //         conv.value =  vm::memory[realadr(mempnt)]; //debug
            std::cout << conv.vchar() << std::endl; //debug
        }
        conv.renew("ch", "HALT");
        vm::memory[realadr(mempnt)] = conv.value;
        mempnt += 1;
    }
    file.close();

//    mempnt = 0;
//    for(int i = 0; i < 256; i++){
//        conv.value = vm::memory[realadr(i)];
//        std::cout << conv.vchar() << std::endl;
//        std::cin >> s;
//    }
}

vm::~vm() {
}

