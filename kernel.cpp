/* 
 * File:   kernel.cpp
 * Author: aidas
 * 
 * Created on May 15, 2010, 2:26 PM
 */

#include "kernel.h"
#include "resource.h"
#include "process.h"
#include <list>

kernel::kernel(realmachine *real) {
    machine= real;
}

int kernel::mainProc(){
    
}

int kernel::createRes(std::string name){
    resource Res;
    Res.message = name;
    Res.father = kernel::current;
    Res.father->childRes.push_back(&Res);
    kernel::resources.push_back(&Res);
    return 0;
};

int kernel::destroyRes(resource * dead) {
    dead->father->childRes.remove(dead);
    kernel::resources.remove(dead);
    delete dead;
    return 0;
};

int kernel::askForRes(std::string name){
    waitingElement we(kernel::current, name);
    kernel::waiting.push_back(we);
    return 0;
};

int kernel::releaseRes(resource* res, process* target, bool PNR){
    res->target = target;
    res->PNR = PNR;
    return 0;
};

int kernel::Resplanner(){
    
};

kernel::~kernel() {
}

