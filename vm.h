/* 
 * File:   vm.h
 * Author: aidas
 *
 * Created on May 3, 2010, 8:01 PM
 */

#ifndef _VM_H
#define	_VM_H

#include <string>

class realmachine;
#include "realmachine.h"

class vm {
public:
    vm(realmachine *, int, std::string);
    virtual ~vm();
    void vhalt();
    void setmemoryfromfile(std::string);
    int step();
    bool finished();
    int stackincrement();
    int stackdecrement();
    
    
    realmachine * machine;
    int ST, ID ;
    short IC ;
    bool finish;
private:

};

#endif	/* _VM_H */

