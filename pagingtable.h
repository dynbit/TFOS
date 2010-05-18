/*
 * File:   pagingtable.h
 * Author: aidas
 *
 * Created on May 11, 2010, 5:42 PM
 */

#ifndef _PAGINGTABLE_H

struct blockinfo {
    bool occupied;
    int vm;
    int block;

};

struct pagingtable {

    blockinfo table[4096];

};
#define	_PAGINGTABLE_H



#endif	/* _PAGINGTABLE_H */

