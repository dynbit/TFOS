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

vm::vm() {
    vm::ST = 255;
    vm::IC = 0;


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

    std::cout << a.vchar();

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

vm::~vm() {
}

