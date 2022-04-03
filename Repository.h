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

    void addVolunteerToClient(volunteer vol, client cli){
        cli.Responded(vol);
        // add the name of the client to the list of the volunteer that respondedTo it
        vol.respondedTo.push_back(cli.name);
    }

    void listOfVolunteers(client cli){
        for( list<volunteer>::iterator iter= cli.responded.begin(); iter != cli.responded.end(); iter++ )
            cout<<iter->name<< ", ";
    }

    void listOfClients(volunteer vol) {
        // iterate through teh list of client names
        for (list<string>::iterator iter = vol.respondedTo.begin(); iter != vol.respondedTo.end(); iter++)
            cout << *iter << ", ";
    }

    void printVolunteersAndClient(){
        for( int i = 0; i < hashVolunteer.tableSize; i++){
            if(hashVolunteer.item[i].flag == full){
                cout << hashVolunteer.item[i].data;
            }
        }
        for( int i = 0; i < hashClient.tableSize; i++){
            if(hashClient.item[i].flag == full){
                cout << hashClient.item[i].data;
            }
        }
    };


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
