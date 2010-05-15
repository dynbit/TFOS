/* 
 * File:   waitingElement.cpp
 * Author: aidas
 * 
 * Created on May 15, 2010, 6:10 PM
 */

#include "waitingElement.h"

waitingElement::waitingElement(process * proc, std::string message) {
    waitingElement::proc = proc;
    waitingElement::message = message;
}

waitingElement::~waitingElement() {
}

