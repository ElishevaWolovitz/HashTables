//
// Created by Gabi Bondi on 31/03/2022.
//
//Done by Elisheva Wolovitz and Gabriella Bondi

#pragma once
#include <iostream>
#include <string>
#include "HashTbls.h"
#include "volunteer.h"
#include "client.h"
#include <list>
#pragma warning (disable:4996)
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

