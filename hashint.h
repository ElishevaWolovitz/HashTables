//
// Created by Gabi Bondi on 30/03/2022.
//

#pragma once
#include <iostream>
#pragma warning (disable:4996)
#include "HashTbls.h"


class hashint : public HashTbls<int,int>{

public:
    hashint(int size): HashTbls(size){};

    int h1(int key){
        for(int i =0; i < tableSize; i++){
            if(item[i].key == key ) return i;
        }
        return -1;
    }

    int h2(int key){ return floor(key*tableSize);}
};



