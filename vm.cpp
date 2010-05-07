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
#include <string>
#include <iostream>
#include <fstream>

vm::vm() {
    ST = 255;
    IC = 96;
    finish = false;


}

int vm::realadr(int hex) {
    return hex;
}


/*
 * VM commands:
 */
void vm::add() {
    if (ST < 255){
    memory[realadr(vm::ST + 1)] += memory[realadr(vm::ST)];
    }
    else{
        memory[realadr(191)] += memory[realadr(vm::ST)];
    }
    stackincrement();
}

void vm::sub() {
    if (ST < 255){
    memory[realadr(vm::ST + 1)] -= memory[realadr(vm::ST)];
    }
    else{
        memory[realadr(191)] -= memory[realadr(vm::ST)];
    }
    stackincrement();
}

void vm::mul() {
    if (ST < 255){
    memory[realadr(vm::ST + 1)] *= memory[realadr(vm::ST)];
    }
    else{
        memory[realadr(191)] *= memory[realadr(vm::ST)];
    }
    stackincrement();
}

void vm::div() {
    if (ST < 255){
    memory[realadr(vm::ST + 1)] /= memory[realadr(vm::ST)];
    }
    else{
        memory[realadr(191)] /= memory[realadr(vm::ST)];
    }
    stackincrement();
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
    stackdecrement();
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
    stackdecrement();
    std::cin >> x;
    memory[realadr(vm::ST)] = x;
}

void vm::ps(int hex) {
    stackdecrement();
    memory[realadr(vm::ST)] = memory[realadr(hex)];
}

void vm::pp(int hex) {
    memory[realadr(hex)] = memory[realadr(vm::ST)];
    stackincrement();
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

void vm::vhalt() {
    finish = true;
    std::cout << std::endl << "VM HALT" << std::endl;
}

bool vm::finished(){
    return finish;
}

int vm::stackdecrement(){
    ST--;
    if (ST < 191) {ST = 255;};
    return 0;
}

int vm::stackincrement(){
    ST++;
    if (ST > 255) {ST = 191;};
    return 0;
}
void vm::setmemoryfromfile(std::string filename) {
    std::string s, temp = "   ";
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
                getline(file, s);
                temp="    ";
                temp[0]=s[1];
                temp[1]=s[2];
                temp[2]=s[3];
                temp[3]=s[4];
                conv.renew("ch", temp);
                vm::memory[realadr(mempnt)] = conv.value;
                mempnt += 1;

                //      std::cout << conv.vchar() << std::endl; //debug
            }
        }
        mempnt = 96;
        while (file >> s && s != "HALT" && mempnt < 192) {
            conv.renew("ch", s);
            vm::memory[realadr(mempnt)] = conv.value;

            //            conv.value = vm::memory[realadr(mempnt)]; //debug
            //std::cout << mempnt << " " << conv.vchar() << std::endl; //debug

            mempnt += 1;
        }
        conv.renew("ch", "HALT");
        vm::memory[realadr(mempnt)] = conv.value;
    }
    file.close();

    //    mempnt = 0;
    //    for(int i = 0; i < 256; i++){
    //        conv.value = vm::memory[realadr(i)];
    //        std::cout << conv.vchar() << std::endl;
    //        std::cin >> s;
    //    }
}

/*
 * completes operation pointed with instruction counter(IC).
 * Increments IC afterwards
 */
int vm::step() {
    if (finish == true) {return 1 ;};
    word conv("10", "0");
    int i = vm::memory[realadr(vm::IC)], command;
    conv.renew("ch", "HALT");
    int halt = conv.value;
    std::string temp, hex = "  ";
    //Addition
    conv.renew("ch", "ADD");
    command = conv.value;
    if (i == command) {
        add();
        //        std::cout << "ADD";
    }
    //Substraction
    conv.renew("ch", "SUB");
    command = conv.value;
    if (i == command) {
        sub();
        //        std::cout << "SUB";
    }
    //Multiplication
    conv.renew("ch", "MUL");
    command = conv.value;
    if (i == command) {
        mul();
        //        std::cout << "MUL";
    }
    //Division
    conv.renew("ch", "DIV");
    command = conv.value;
    if (i == command) {
        div();
        //        std::cout << "DIV";
    }
    //    put data char
    conv.renew("ch", "PDCH");
    command = conv.value;
    if (i == command) {
        pdch();
        //        std::cout << "PDCH";
    }
    //put data number
    conv.renew("ch", "PDNB");
    command = conv.value;
    if (i == command) {
        pdnb();
        //        std::cout << "PDNB";
    }
    //get data char
    conv.renew("ch", "GDCH");
    command = conv.value;
    if (i == command) {
        gdch();
        //        std::cout << "GDCH";
    }
    //Get data number
    conv.renew("ch", "GDNB");
    command = conv.value;
    if (i == command) {
        gdnb();
        //        std::cout << "GDNB";
    }

    //    PUSH
    conv.value = i;
    temp = conv.vchar();
    if (temp[0] == 'P' && temp[1] == 'S') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        ps(conv.value);
        //        std::cout << "PS";
    }
    //  POP
    conv.value = i;
    temp = conv.vchar();
    if (temp[0] == 'P' && temp[1] == 'P') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        pp(conv.value);
        //        std::cout << "PP";
    }

    //Jump if equal
    conv.value = i;
    temp = conv.vchar();

    if (temp[0] == 'J' && temp[1] == 'E') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        je(conv.value);
        //        std::cout << "JE"<< conv.decimal();
    }
    //Jump if not equal
    conv.value = i;
    temp = conv.vchar();
    if (temp[0] == 'J' && temp[1] == 'N') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        jn(conv.value);
        //        std::cout << "JN";
    }
    //  Jump
    conv.value = i;
    temp = conv.vchar();
    if (temp[0] == 'J' && temp[1] == 'M') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        jm(conv.value);
        //        std::cout << "JM";
    }

    conv.renew("ch", "HALT");
    command = conv.value;
    if (i == command) {
        vhalt();
        //        std::cout << "HALT";
    }
    vm::IC += 1;

}

void vm::printstack(){
    std::cout << "STACK" << std::endl;
    for (int i=192 ; i < 256; i++){
        std::cout << memory[realadr(i)] << std::endl;
    }
}

vm::~vm() {
}

