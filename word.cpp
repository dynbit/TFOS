/* 
 * File:   word.cpp
 * Author: aidas
 * 
 * Created on May 3, 2010, 2:03 AM
 */

#include "word.h"
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <limits>
#include <cstdlib>

#include "word.h"

word::word(std::string sys, std::string numbers) {
    renew(sys, numbers);
}

/*
 * renew. Function to chance value of word. Given sys{"10", "16", "ch"} and
 * string with correct number or char set converts it into integer.
 */
void word::renew(std::string sys, std::string numbers) {
     std::stringstream ss;
    unsigned int x = 0;
    if (sys == "16") {
        ss << std::hex << numbers;
        ss >> x;
        //std::cout << static_cast<int> (x);
    }

    if (sys == "10") {
        ss << std::dec << numbers;
        ss >> x;
        //std::cout << static_cast<int> (x);
    }

    if (sys == "ch") {
        if (numbers.length() < 5) {
            for (unsigned int i = 0; i < numbers.length(); i++) {
                x *= 256;
                x += int(numbers[i]);

            }
            for (int i = numbers.length(); i < 4; i++) {
                x *= 256;
            }
        } else {
            x = 0;
        }
    }
    //       if (sys == 2) {
    //           x= std::bitset<std::numeric_limits<unsigned long>::digits>(numbers).to_ulong();
    //           std::cout << static_cast<int>(x);
    //       }

    word::value = x;
}

//returns decimal representation as a string
std::string word::decimal() {
    std::stringstream ss; //create a stringstream
    ss << word::value; //add number to the stream
    return ss.str(); //return a string with the contents of the stream
}
//returns hexadimal representation
std::string word::hexadimal() {

    std::stringstream ss;
    ss << std::hex << word::value;
    std::string retval;
    retval = ss.str().c_str();
    return retval;

}
//returns representation as 4 chars
std::string word::vchar() {

    std::div_t x;
    std::string retval = "    ";
    x = div(word::value, 256);
    retval[3] = char(x.rem);
    x = div(x.quot, 256);
    retval[2] = char(x.rem);
    x = div(x.quot, 256);
    retval[1] = char(x.rem);
    x = div(x.quot, 256);
    retval[0] = char(x.rem);
    return retval;
}

word::~word() {

}



