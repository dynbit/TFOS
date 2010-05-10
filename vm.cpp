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

vm::vm(realmachine * real, int number, std::string file) {
    ID = number;
    ST = 255;
    IC = 95;
    finish = false;
    machine =  real;
    setmemoryfromfile(file);
}

//stops further execution of virtual machine
void vm::vhalt() {
    finish = true;
//    std::cout << std::endl << "VM HALT" << std::endl;
}


//controls stack pointer
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

// reads file for data and commands sequence
void vm::setmemoryfromfile(std::string filename) {
    std::string s, temp = "   ";
    std::ifstream file(filename.c_str());
    word conv("10", "0");
    short mempnt = 0;
    file >> s;
    if (s == "DATA") {
        while (file >> s && s != "CODE" && mempnt < 96) {
            if (s == "DE") {
                machine->memory[machine->realadr(this, mempnt)] = 0;
                mempnt += 1;
            } else if (s == "DW") {
                file >> s;
                conv.renew("10", s);
                machine->memory[machine->realadr(this, mempnt)] = conv.value;
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
                machine->memory[machine->realadr(this, mempnt)] = conv.value;
                mempnt += 1;

                //      std::cout << conv.vchar() << std::endl; //debug
            }
        }
        mempnt = 95;
        while (file >> s && s != "HALT" && mempnt < 191) {
            conv.renew("ch", s);
            machine->memory[machine->realadr(this, mempnt)] = conv.value;

            //            conv.value = machine->memory[realadr(mempnt)]; //debug
            //std::cout << mempnt << " " << conv.vchar() << std::endl; //debug

            mempnt += 1;
        }
        conv.renew("ch", "HALT");
        machine->memory[machine->realadr(this, mempnt)] = conv.value;
    }
    file.close();

    //    mempnt = 0;
    //    for(int i = 0; i < 256; i++){
    //        conv.value = machine->memory[realadr(i)];
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
    int i = machine->memory[machine->realadr(this, IC)], command;
    conv.renew("ch", "HALT");
    std::string temp, hex = "  ";
    //Addition
    conv.renew("ch", "ADD");
    command = conv.value;
    if (i == command) {
        machine->add(this);
        //        std::cout << "ADD";
    }
    //Substraction
    conv.renew("ch", "SUB");
    command = conv.value;
    if (i == command) {
        machine->sub(this);
        //        std::cout << "SUB";
    }
    //Multiplication
    conv.renew("ch", "MUL");
    command = conv.value;
    if (i == command) {
        machine->mul(this);
        //        std::cout << "MUL";
    }
    //Division
    conv.renew("ch", "DIV");
    command = conv.value;
    if (i == command) {
        machine->div(this);
        //        std::cout << "DIV";
    }
    //    put data char
    conv.renew("ch", "PDCH");
    command = conv.value;
    if (i == command) {
        machine->pdch(this);
        //        std::cout << "PDCH";
    }
    //put data number
    conv.renew("ch", "PDNB");
    command = conv.value;
    if (i == command) {
        machine->pdnb(this);
        //        std::cout << "PDNB";
    }
    //get data char
    conv.renew("ch", "GDCH");
    command = conv.value;
    if (i == command) {
        machine->gdch(this);
        //        std::cout << "GDCH";
    }
    //Get data number
    conv.renew("ch", "GDNB");
    command = conv.value;
    if (i == command) {
        machine->gdnb(this);
        //        std::cout << "GDNB";
    }

    //    PUSH
    conv.value = i;
    temp = conv.vchar();
    if (temp[0] == 'P' && temp[1] == 'S') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        machine->ps(this, conv.value);
        //        std::cout << "PS";
    }
    //  POP
    conv.value = i;
    temp = conv.vchar();
    if (temp[0] == 'P' && temp[1] == 'P') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        machine->pp(this, conv.value);
        //        std::cout << "PP";
    }

    //Jump if equal
    conv.value = i;
    temp = conv.vchar();

    if (temp[0] == 'J' && temp[1] == 'E') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        machine->je(this, conv.value);
        //        std::cout << "JE"<< conv.decimal();
    }
    //Jump if not equal
    conv.value = i;
    temp = conv.vchar();
    if (temp[0] == 'J' && temp[1] == 'N') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        machine->jn(this, conv.value);
        //        std::cout << "JN";
    }
    //  Jump
    conv.value = i;
    temp = conv.vchar();
    if (temp[0] == 'J' && temp[1] == 'M') {
        hex[0] = temp[2];
        hex[1] = temp[3];
        conv.renew("16", hex);
        machine->jm(this, conv.value);
        //        std::cout << "JM";
    }

    conv.renew("ch", "HALT");
    command = conv.value;
    if (i == command) {
        vhalt();
        //        std::cout << "HALT";
    }
    IC += 1;
}


vm::~vm() {
}

