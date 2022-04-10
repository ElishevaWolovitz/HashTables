//
// Created by Gabi Bondi on 08/04/2022.
//

#ifndef Q2_HASHCLIENT_H
#define Q2_HASHCLIENT_H

#include <iostream>
#include "client.h"
#include "HashTbls.h"
using namespace std;

class HashClient : public HashTbls<client, int>
{
public:

    HashClient(): HashTbls<client, int>(){};

    HashClient(int size): HashTbls<client, int>(size){};

    int h1(int key)
    {
        return (key%tableSize);
    }

    int h2(int key)
    {
        return (1+(key%tableSize));
    }
};

#endif //Q2_HASHCLIENT_H
