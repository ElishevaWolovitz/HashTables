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

class HashVolunteer : public HashTbls<volunteer, string>
{
public:
    int h1(string key)
    {
        for (int i = 0; i < tableSize;)
        {
            if (item[i].key != key)
                i++;
            else
                return i;
        }
        return -1;
    }
    int h2(string key)
    {
        int x = hash(key, 0);
        int y = h1(key);
        int z = hash(key, y);
        if (y == -1)
            return -1;
        if (y >= x)
            return (y - x) ;
        else
            return (y + ((tableSize-1) - x));
    }
};

