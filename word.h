/* 
 * File:   word.h
 * Author: aidas
 *
 * Created on May 3, 2010, 2:03 AM
 */


#ifndef _WORD_H
#define	_WORD_H


#include <string>


class word {
public:
    word(std::string, std::string );
    std::string decimal();
    std::string hexadimal();
    std::string vchar();
    virtual ~word();
    int value;
private:
    
};

#endif	/* _WORD_H */

