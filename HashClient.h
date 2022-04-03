//
// Created by Gabi Bondi on 31/03/2022.
//

#pragma once
#include <iostream>
#include <string>
#include "HashTbls.h"
#include "volunteer.h"
#include "client.h"
#pragma warning (disable:4996)
using namespace std;

class HashClient : public HashTbls<client, int>
{
public:

    HashClient(): HashTbls<client, int>(){};

    HashClient(int size): HashTbls<client, int>(size){};

    int h1(int key)
    {
        for (int i = 0; i < capacity;)
        {
            if (item[i].key != key)
                i++;
            else
                return i;
        }
        return -1;
    }
    int h2(int key)
    {
        int x = hash(key, 0);
        int y = h1(key);
        int z = hash(key, y);
        if (y == -1)
            return -1;
        if (y >= x)
            return (y - x);
        else
            return (y + ((tableSize - 1) - x));
    }
};

