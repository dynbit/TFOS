/* 
 * File:   realmachine.h
 * Author: aidas
 *
 * Created on May 3, 2010, 7:38 PM
 */

#ifndef _REALMACHINE_H
#define	_REALMACHINE_H

class vm;
#include "vm.h"

class realmachine {
public:
    realmachine();
    int realadr(vm *, int);
    void add(vm *);
    void sub(vm *);
    void mul(vm *);
    void div(vm *);
    void pdch(vm *);
    void pdnb(vm *);
    void gdch(vm *);
    void gdnb(vm *);
    void ps(vm *, int);
    void pp(vm *, int);
    void je(vm *, short);
    void jn(vm *, short);
    void jm(vm *, short);
    virtual ~realmachine();
private:


};

#endif	/* _REALMACHINE_H */

