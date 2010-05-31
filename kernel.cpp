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
#include <algorithm>


kernel::kernel(realmachine *real) {
    machine = real;
}

int kernel::mainProc() {

}

std::string globalName;

bool nameBool(resource* res){
    if (res->name == globalName) {
        return true;
    };
    return false;
}

resource * kernel::findRes(std::string name){
    std::list<process*>::iterator result;
    globalName = name;
    result = std::find_if(kernel::resources.begin(),kernel::resources.end(), nameBool);
    return result;

}

int kernel::createRes(std::string name, process* target) {
    resource *Res = findRes(name);
    Res.name = name;
    Res.father = kernel::current;
    Res.father->childRes.push_back(&Res);
    kernel::resources.push_back(&Res);
    Resplanner();
    return 0;
};

int kernel::destroyRes(resource * dead) {
    dead->father->childRes.remove(dead);
    kernel::resources.remove(dead);
    delete dead;
    Resplanner();
    return 0;
};

int kernel::askForRes(std::string name) {
    waitingElement we(kernel::current, name);
    kernel::waiting.push_back(we);
    Resplanner();
    return 0;
};

int kernel::releaseRes(resource* res, process* target, bool PNR) {
    res->target = target;
    res->PNR = PNR;
    Resplanner();
    return 0;
};

int kernel::Resplanner() {
    return 0;
};



int kernel::createProc(std::string name, int priority) {
    process proc(name, priority);
    proc.father = kernel::current;
    kernel::processes.push_back(&proc);
    proc.father->childProc.push_back(&proc);
    proc.childProc.clear;
    proc.childRes.clear;
    proc.curRes.clear;
    proc.state = "READY";
    return 0;
};

int kernel::destroyProc(process* dead) {
    dead->father->childProc.remove(dead);
    kernel::processes.remove(dead);
    kernel::ready.remove(dead);
    //nebaigtas

    return 0;
};

int kernel::stopProc(process* proc) {
    return 0;
};

int kernel::activateProc(process* proc) {
    return 0;
};

int kernel::Scheduler() {
    return 0;
};

kernel::~kernel() {
}

