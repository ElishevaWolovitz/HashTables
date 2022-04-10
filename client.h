//
// Created by Gabi Bondi on 08/04/2022.
//

#ifndef Q2_CLIENT_H
#define Q2_CLIENT_H

#include <string>
#include <iostream>
#include "volunteer.h"
using namespace std;

class client {

public:
    string name;
    string address;
    int phoneNumber;
    //static list<volunteer> responded;
    volunteer responded[100] = {};
    //keep track of where we are in the responded array
    static int i;

    //default constructor
    client(){
        name = "";
        address = "";
        phoneNumber = 0;
        client::i = 0;
    }


    // constructor that assigns string, address and phoneNumber
    client(string name, string address, int phoneNumber){
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        client::i = 0;
    }

    //adds a volunteer to the list of responded
    void Responded(volunteer vol) {

        //make sure there are no duplicates
        for(int j = 0; j< client::i; j++){
            if(responded[j] == vol)
                return;
        }

        //responded.push_back(vol);
        responded[client::i] = vol;
        i++;
    }

    //client destructor
    ~client(){
        delete[] this;
    }

    //equals operator
    bool operator==(const client& client1) const {
        return name == client1.name;
    }

    //assignment operator
    void operator = (const client& client1){
        name = client1.name;
        address = client1.address;
        phoneNumber = client1.phoneNumber;
        for(int j = 0; j < client::i; j++){
            responded[j] = client1.responded[j];
        }
    }

    //input operator
    friend istream& operator >>(istream& is, client client1){
        int phoneNumber; string name; string address; volunteer vol;
        is >> phoneNumber;
        is >> name;
        is >> address;
        is >> (vol);

        client1.phoneNumber = phoneNumber;
        client1.name = name;
        client1.address = address;
        client1.Responded(vol);

        return is;
    }


    //output operator
    friend ostream& operator <<(ostream& os, client client1){
        os<<client1.phoneNumber<<", "<<client1.address<<", "<<client1.phoneNumber<<endl;
        for(int j = 0; j< i; j++){
            os << client1.responded[j] << endl;
        }
        return os;
    }


};


#endif //Q2_CLIENT_H
