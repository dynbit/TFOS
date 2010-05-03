/* 
 * File:   CPU.h
 * Author: aidas
 *
 * Created on May 2, 2010, 11:34 PM
 */

#ifndef _CPU_H
#define	_CPU_H


#include "word.h"

class CPU {
public:
    CPU();
    virtual ~CPU();

private:
    int PTR;
    int SP;
    short IC;
    bool C;

    bool PI, SI, IOI, TI;
    bool CH1, CH2, CH3;

    bool mode;
};

#endif	/* _CPU_H */

