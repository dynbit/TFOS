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

int realmachine::realadr(vm * vm, int hex){
    return hex;
}

realmachine::~realmachine() {
}

void realmachine::add(vm * vm) {
    if (vm->ST < 255){
    vm->memory[realadr(vm, vm->ST + 1)] += vm->memory[realadr(vm, vm->ST)];
    }
    else{
        vm->memory[realadr(vm, 191)] += vm->memory[realadr(vm, vm->ST)];
    }
    vm->stackincrement();
}

void realmachine::sub(vm * vm) {
    if (vm->ST < 255){
    vm->memory[realadr(vm, vm->ST + 1)] -= vm->memory[realadr(vm, vm->ST)];
    }
    else{
        vm->memory[realadr(vm, 191)] -= vm->memory[realadr(vm, vm->ST)];
    }
    vm->stackincrement();
}

void realmachine::mul(vm * vm) {
    if (vm->ST < 255){
    vm->memory[realadr(vm, vm->ST + 1)] *= vm->memory[realadr(vm, vm->ST)];
    }
    else{
        vm->memory[realadr(vm, 191)] *= vm->memory[realadr(vm, vm->ST)];
    }
    vm->stackincrement();
}

void realmachine::div(vm * vm) {
    if (vm->ST < 255){
    vm->memory[realadr(vm, vm->ST + 1)] /= vm->memory[realadr(vm, vm->ST)];
    }
    else{
        vm->memory[realadr(vm, 191)] /= vm->memory[realadr(vm, vm->ST)];
    }
    vm->stackincrement();
}

void realmachine::pdch(vm * vm) {
    int i = vm->memory[realadr(vm, vm->ST)];
    std::string s;
    std::stringstream out;
    out << i;
    s = out.str();

    word a("10", s);
    std::cout << a.vchar();
}

void realmachine::pdnb(vm * vm) {
    std::cout << vm->memory[realadr(vm, vm->ST)];
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
    vm->memory[realadr(vm, vm->ST)] = a.value;
}

void realmachine::gdnb(vm * vm) {
    int x;
    vm->stackdecrement();
    std::cin >> x;
    vm->memory[realadr(vm, vm->ST)] = x;
}

void realmachine::ps(vm * vm, int hex) {
    vm->stackdecrement();
    vm->memory[realadr(vm, vm->ST)] = vm->memory[realadr(vm, hex)];
}

void realmachine::pp(vm * vm, int hex) {
    vm->memory[realadr(vm, hex)] = vm->memory[realadr(vm, vm->ST)];
    vm->stackincrement();
}

void realmachine::je(vm * vm, short adr) {
    if (vm->memory[realadr(vm, vm->ST)] == 0) {
        vm->IC = adr;
    }
}

void realmachine::jn(vm * vm, short adr) {
    if (vm->memory[realadr(vm, vm->ST)] != 0) {
        vm->IC = adr;
    }

}

void realmachine::jm(vm * vm, short adr) {
    vm->IC = adr;
}