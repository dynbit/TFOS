/* 
 * File:   kernel.h
 * Author: aidas
 *
 * Created on May 15, 2010, 2:26 PM
 */

#ifndef _KERNEL_H
#define	_KERNEL_H

#include <list>
#include <string>
#include "waitingElement.h"

class process;
class resource;
class realmachine;

class kernel {
public:
    kernel(realmachine*);
    virtual ~kernel();

    std::list<process*> processes;      //visi procesai
    std::list<resource*> resources;     //visi resursai
    process *current;                   //einamasis procesas
    std::list<process*> ready;          //pasiruošę procesai
    realmachine * machine;              //reali mašina

    resource * findRes(std::string);
    int createRes(std::string);
    int destroyRes(resource*);
    int askForRes(std::string);
    int releaseRes(resource*, process*, bool);
    int Resplanner();

    int createProc(std::string, int);
    int destroyProc(process*);
    int stopProc(process*);
    int activateProc(process*);
    int Scheduler();
    
    int mainProc();
private:

};

#endif	/* _KERNEL_H */

