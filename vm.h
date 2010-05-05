/* 
 * File:   vm.h
 * Author: aidas
 *
 * Created on May 3, 2010, 8:01 PM
 */

#ifndef _VM_H
#define	_VM_H

#include <string>


class vm {
public:
    vm();
    virtual ~vm();
    int realadr(int);
    void add();
    void sub();
    void mul();
    void div();
    void pdch();
    void pdnb();
    void gdch();
    void gdnb();
    void ps(int);
    void pp(int);
    void je(short);
    void jn(short);
    void jm(short);
    void halt();
    void setmemoryfromfile(std::string);
    int step();
private:
    int ST ;
    short IC ;
    int memory[256];
};

#endif	/* _VM_H */

