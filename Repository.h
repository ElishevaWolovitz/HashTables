//
// Created by Gabi Bondi on 31/03/2022.
//
#include <iostream>
#include <string>
#include "HashTbls.h"
#include "hashint.h"
#include "HashVolunteer.h"
#include "HashClient.h"
#include "client.h"
using namespace std;

#ifndef Q2_REPOSITORY_H
#define Q2_REPOSITORY_H

class Repository {
    HashClient hashClient;
    HashVolunteer hashVolunteer;

    Repository(){
        hashClient = HashClient(100);
        hashVolunteer = HashVolunteer(100);
    }

    void delVolunteer(volunteer vol){
        hashVolunteer.HashDelete(vol,vol.name);
    }

    void delClient(client cli){
        hashClient.HashDelete(cli,cli.phoneNumber);
    }

    void addVolunteer(volunteer vol){
        hashVolunteer.HashInsert(vol,vol.name);
    }

    void addClient(client cli){
        hashClient.HashInsert(cli,cli.phoneNumber);
    }

    void addVolunteerToClient(volunteer vol, client cli){}

    void listOfVolunteers(client cli){}

    void listOfClients(volunteer vol){}


};

#endif //Q2_REPOSITORY_H

/*class hashint : public HashTbls<int,int>{

public:
    hashint(int size): HashTbls(size){};

    int h1(int key){
        for(int i =0; i < tableSize; i++){
            if(item[i].key == key ) return i;
        }
        return -1;
    }

    int h2(int key){ return floor(key*tableSize);}
};*/
