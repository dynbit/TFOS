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

    std::string message;
    process * target;
    process * father;
    bool PNR;
    virtual ~resource();
private:

};

#endif	/* _RESOURCE_H */

