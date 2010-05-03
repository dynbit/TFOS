///*
// * File:   virtualstack.cpp
// * Author: aidas
// *
// * Created on May 3, 2010, 3:13 AM
// */
//
//#include "virtualstack.h"
//
//virtualstack::virtualstack() {
//    word a(10, "0");
//    virtualstack::current = 0;
//    virtualstack::maxocr = 2;
//    for (int i = 0; i < virtualstack::maxocr; i++) {
//        virtualstack::vstack.push(a);
//    }
//
//}
//
//word virtualstack::vpop() {
//    if (virtualstack::current > 0) {
//        virtualstack::current--;
//        return virtualstack::vstack.pop();
//
//    } else {
//        virtualstack::vstack.pop();
//        std::stack<word> temp;
//        word a(10, "0");
//        for (int i = 0; i < virtualstack::maxocr; i++) {
//            temp.push(a);
//        }
//        virtualstack::vstack = temp;
//        virtualstack::current = virtualstack::maxocr;
//    }
//
//}
//
//void virtualstack::vpush(word a) {
//    if (virtualstack::current < virtualstack::maxocr) {
//        virtualstack::vstack.push(a);
//        virtualstack::current++;
//    } else {
//        virtualstack::vstack.pop();
//        std::stack<word> temp;
//        temp.push(a);
//        for (int i = 0; i < virtualstack::maxocr; i++) {
//            temp.push(virtualstack::vstack.pop());
//        }
//        for (int i = 0; i < virtualstack::maxocr; i++) {
//            virtualstack::vstack.push(temp.pop());
//        }
//    }
//}
//
//word virtualstack::vtop() {
//    return virtualstack::vstack.top();
//}
//
//virtualstack::~virtualstack() {
//}
//
