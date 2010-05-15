/* 
 * File:   process.cpp
 * Author: aidas
 * 
 * Created on May 15, 2010, 3:06 PM
 */

#include "process.h"

process::process(process *father, std::string name, int priority) {
    process::father = father;
    process::name = name;
    process::priority = priority;
}

process::~process() {
}

