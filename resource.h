/* 
 * File:   resource.h
 * Author: aidas
 *
 * Created on May 15, 2010, 3:23 PM
 */

#ifndef _RESOURCE_H
#define	_RESOURCE_H

#include <string>
class process;

class resource {
public:
    resource();
    int ID;

    std::string name;
    std::list<process*> father;             //sąrašas elementų tėvų
    std::list<process*>  elements;          //sąrašas esamų resurso elementų. nill jeigu visiem prieinamas, arba process* jeigu kažkokiam specifiniam procesui
    std::list<process*> waiting;            //sąrašas procesų laukiančių resurso
    bool PNR;                               //pakartotino naudojimo resursas
    virtual ~resource();
private:

};

#endif	/* _RESOURCE_H */

