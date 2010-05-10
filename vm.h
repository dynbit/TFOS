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
    void step();
    int stackincrement();
    int stackdecrement();
    
    
    realmachine * machine; 	//pointer to real machine in which virtual is working
    int ST, ID ; 			//register and virtual machine's ID
    short IC ; 				//register
    bool finish; 			// bool to notice if vm has finished working
private:

};

#endif	/* _VM_H */

