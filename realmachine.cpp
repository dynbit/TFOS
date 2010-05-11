/* 
 * File:   realmachine.cpp
 * Author: aidas
 * 
 * Created on May 3, 2010, 7:38 PM
 */

#include "realmachine.h"
#include "vm.h"
#include "word.h"
#include <sstream>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

realmachine::realmachine() {
}


//function to get real adress, knowing virtual machine and adr in virtual's machine memory
int realmachine::realadr(vm * vm, short hex){
    int empty = -1;

    for(int i=0; i <4096; i++){
        if ((empty == -1) && (ptable.table[i].occupied == false)) {
            empty = i;
        }
        if ((ptable.table[i].vm == vm->ID) && (hex - ptable.table[i].block * 16 < 16) && (hex - ptable.table[i].block * 16 >= 0)){
            return i*16 + hex % 16;
        }
    }
    if (empty != -1){
        ptable.table[empty].occupied = true;
        ptable.table[empty].vm = vm->ID;
        ptable.table[empty].block = hex / 16;
        return empty*16 + hex % 16;
    }

    return -1; // no free space
}

realmachine::~realmachine() {
}


// asempbler like commands, see https://docs.google.com/Doc?docid=0AXGXphr0CjTZZGc0aDNjYzJfNDcwZG1qeDZtZjY&hl=en for more details
void realmachine::add(vm * vm) {
    if (vm->ST < 255){
    memory[realadr(vm, vm->ST + 1)] += memory[realadr(vm, vm->ST)];
    }
    else{
        memory[realadr(vm, 191)] += memory[realadr(vm, vm->ST)];
    }
    vm->stackincrement();
}

void realmachine::sub(vm * vm) {
    if (vm->ST < 255){
    memory[realadr(vm, vm->ST + 1)] -= memory[realadr(vm, vm->ST)];
    }
    else{
        memory[realadr(vm, 191)] -= memory[realadr(vm, vm->ST)];
    }
    vm->stackincrement();
}

void realmachine::mul(vm * vm) {
    if (vm->ST < 255){
    memory[realadr(vm, vm->ST + 1)] *= memory[realadr(vm, vm->ST)];
    }
    else{
        memory[realadr(vm, 191)] *= memory[realadr(vm, vm->ST)];
    }
    vm->stackincrement();
}

void realmachine::div(vm * vm) {
    if (vm->ST < 255){
    memory[realadr(vm, vm->ST + 1)] /= memory[realadr(vm, vm->ST)];
    }
    else{
        memory[realadr(vm, 191)] /= memory[realadr(vm, vm->ST)];
    }
    vm->stackincrement();
}

void realmachine::pdch(vm * vm) {
    int i = memory[realadr(vm, vm->ST)];
    std::string s;
    std::stringstream out;
    out << i;
    s = out.str();

    word a("10", s);
    std::cout << a.vchar();
}

void realmachine::pdnb(vm * vm) {
    std::cout << memory[realadr(vm, vm->ST)];
}



void realmachine::gdch(vm * vm) {
    std::string x, y;
    vm->stackdecrement();
    std::getline(std::cin, y);
    x = "    ";
    x[0] = y[0];
    x[1] = y[1];
    x[2] = y[2];
    x[3] = y[3];
    word a("ch", x);
    memory[realadr(vm, vm->ST)] = a.value;
}

void realmachine::gdnb(vm * vm) {
    int x;
    vm->stackdecrement();
    std::cin >> x;
    memory[realadr(vm, vm->ST)] = x;
}

void realmachine::ps(vm * vm, int hex) {
    vm->stackdecrement();
    memory[realadr(vm, vm->ST)] = memory[realadr(vm, hex)];
}

void realmachine::pp(vm * vm, int hex) {
    memory[realadr(vm, hex)] = memory[realadr(vm, vm->ST)];
    vm->stackincrement();
}

void realmachine::je(vm * vm, short adr) {
    if (memory[realadr(vm, vm->ST)] == 0) {
        vm->IC = adr;
    }
}

void realmachine::jn(vm * vm, short adr) {
    if (memory[realadr(vm, vm->ST)] != 0) {
        vm->IC = adr;
    }

}

void realmachine::jm(vm * vm, short adr) {
    vm->IC = adr;
}