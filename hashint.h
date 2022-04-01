//
// Created by Gabi Bondi on 30/03/2022.
//

#ifndef Q2_HASHINT_H
#define Q2_HASHINT_H
#include "HashTbls.h"


class hashint : HashTbls<int,int>{

    //HashTbls<int,int> table1;

public:
    hashint(int n){
        HashTbls<int,int> (n);
    }

private:
    int h1(int key){
            for(int i =0; i < tableSize, i++){
                if(item[i] == key ) return i;
            }
            return -1;
    }

    int h2(int key){ return floor(key.tableSize);}
};





#endif //Q2_HASHINT_H
