/* 
 * File:   process.h
 * Author: aidas
 *
 * Created on May 15, 2010, 3:06 PM
 */

#ifndef _PROCESS_H
#define	_PROCESS_H

#include "resource.h"
#include <list>

class vm;


// tėvinė visų procesų klasė
class process {
public:
    process(process*, std::string, int);    //tėvas, pavadimas, priority
    virtual ~process();

    virtual int step();                     //vienas proceso žingsnis. Grąžina kiek time vienetų sunaudojo

    int ID;

    std::string state;                      
    process * father;
    std::string name;
    int priority;
    std::list<resource*> childRes;
    std::list<process*> childProc;
    std::list<resource*> curRes;
    
private:

};

#endif	/* _PROCESS_H */

