//
// Created by Gabi Bondi on 08/04/2022.
//

#ifndef Q2_REPOSITORY_H
#define Q2_REPOSITORY_H

# include <iostream>
#include "HashClient.h"
#include "HashVolunteer.h"
using namespace std;


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
    static void addVolunteerToClient(volunteer vol, client cli){
        //responded checks if volunteer is in there and if not deletes it
        cli.Responded(vol);
        // add the name of the client to the list of the volunteer that respondedTo it
        vol.respondedTo[volunteer::k] = cli.name;
    }

    //Given a caller, print the names of the volunteers who responded to the client
    static void listOfVolunteers(client cli){
        for(int j = 0; j < client::i ; j++){
            cout << cli.responded[j]<< endl;
        }
    }

    //Given a volunteer, print the names of the callers to which he responded
    static void listOfClients(volunteer vol) {
        //iterate through the array of client names
        for(int j = 0; j < volunteer::k; j++){
            cout<< vol.respondedTo[j]<< endl;
        }
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
    }


};

#endif //Q2_REPOSITORY_H
