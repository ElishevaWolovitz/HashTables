//
// Created by Gabi Bondi on 29/03/2022.
//
//Done by Elisheva Wolovitz and Gabriella Bondi

#ifndef Q2_CLIENT_H
#define Q2_CLIENT_H
#include <string>
#include <iostream>
#include <list>
#include "volunteer.h"
using namespace std;

class client {

public:
    string name;
    string address;
    int phoneNumber;
    static list<volunteer> responded;

    //default constructor
    client(){
        name = "";
        address = "";
        phoneNumber = 0;
        responded.empty();
    }


    // constructor that assigns string, address and phoneNumber
    client(string name, string address, int phoneNumber){
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
    }

    //adds a volunteer to the list of responded
    void Responded(volunteer vol) {
       responded.push_back(vol);

        //make sure there are no duplicates
        responded.unique();

    }

    //client destructor
    ~client(){
        delete[] this;
    }

    //equals operator
    void operator==(const client& client1) const{
        name == client1.name;
    }

    //assignment operator
   void operator = (const client& client1){
        name = client1.name;
        address = client1.address;
        phoneNumber = client1.phoneNumber;
        responded = client1.responded;
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
        for (auto & it : responded) {
                os << it << ", " << endl;  //might need to change back to cout
        }
        return os;
    }



};


#endif //Q2_CLIENT_H
