//
// Created by Gabi Bondi on 08/04/2022.
//

#ifndef Q2_HASHVOLUNTEER_H
#define Q2_HASHVOLUNTEER_H

#include <iostream>
#include <string>
#include "HashTbls.h"
#include "volunteer.h"
using namespace std;

class HashVolunteer : public HashTbls<volunteer, string>
{
public:

    HashVolunteer():HashTbls<volunteer, string>(){};

    HashVolunteer(int size): HashTbls<volunteer, string>(size){};

    int h1(string key)
    {
        //fins the ascii value of the first letter of you string then treats it like an int (like in client)
        char firstLetter = key[0];
        return (((int)firstLetter)%tableSize);
    }

    int h2(string key)
    {
        char firstLetter = key[0];
        //function we chose for double hashing
        return (1+(((int)firstLetter)%tableSize));
    }
};



#endif //Q2_HASHVOLUNTEER_H
