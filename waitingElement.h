/* 
 * File:   waitingElement.h
 * Author: aidas
 *
 * Created on May 15, 2010, 6:10 PM
 */

#ifndef _WAITINGELEMENT_H
#define	_WAITINGELEMENT_H

#include <string>
class process;
class waitingElement {
public:
    waitingElement(process*, std::string);
    virtual ~waitingElement();

    process * proc;
    std::string message;
private:

};

#endif	/* _WAITINGELEMENT_H */

