//
// Created by Gabi Bondi on 31/03/2022.
//
//Done by Elisheva Wolovitz and Gabriella Bondi

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

    //Initializing both hash tables to size 100,
public: Repository(){
        hashClient = HashClient(100);
        hashVolunteer = HashVolunteer(100);
    }

    //deleting a volunteer
    void delVolunteer(volunteer vol){
        hashVolunteer.HashDelete(vol,vol.name);
    }

    //deleting a new caller
    void delClient(client cli){
        hashClient.HashDelete(cli,cli.phoneNumber);
    }

    //Adding a volunteer
    void addVolunteer(volunteer vol){
        hashVolunteer.HashInsert(vol,vol.name);
    }

    //Adding a new caller
    void addClient(client cli){
        hashClient.HashInsert(cli,cli.phoneNumber);
    }

    //Adding a volunteer as a responder to a call (must first verify that the volunteer exists
    //in the repository)
    void addVolunteerToClient(volunteer vol, client cli){
        cli.Responded(vol);
        // add the name of the client to the list of the volunteer that respondedTo it
        vol.respondedTo.push_back(cli.name);
    }

    //Given a caller, print the names of the volunteers who responded to him
    void listOfVolunteers(client cli){
        for( list<volunteer>::iterator iter= cli.responded.begin(); iter != cli.responded.end(); iter++ )
            cout<<iter->name<< ", ";
    }

    //Given a volunteer, print the names of the callers to which he responded
    void listOfClients(volunteer vol) {
        // iterate through teh list of client names
        for (list<string>::iterator iter = vol.respondedTo.begin(); iter != vol.respondedTo.end(); iter++)
            cout << *iter << ", ";
    }

    //Printing the callers' table and the volunteers' table
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

