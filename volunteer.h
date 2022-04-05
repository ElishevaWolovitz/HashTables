//
// Created by Gabi Bondi on 29/03/2022.
//
//Done by Elisheva Wolovitz and Gabriella Bondi

#ifndef Q2_VOLUNTEER_H
#define Q2_VOLUNTEER_H
#include <string>
#include <iostream>
#include <list>
#include <string>
using namespace std;


class volunteer {

public:
    string name;
    string address;
    int phoneNumber;
    // a list of client names that the volunteer responded to
    static list<string> respondedTo;

public:

    //default constructor
    volunteer(){
        name = "";
        address = "";
        phoneNumber = 0;
    }

    //constructor that sets the name, address and phone number of the volunteer
    volunteer(string name, string address, int phoneNumber){
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
    }

    //volunteer destructor
    ~volunteer(){
        delete[] this;
    }

    //equals operator
    bool operator==(const volunteer& vol) const{
        return (name == vol.name);
    }

    //assignment operator
    void operator = (const volunteer& vol){
        name = vol.name;
        address = vol.address;
        phoneNumber = vol.phoneNumber;
    }

    //input operator
    friend istream& operator >>(istream& is, volunteer vol){
        int phoneNumber; string name; string address;
        is >> phoneNumber;
        is >> name;
        is >> address;

        vol.phoneNumber = phoneNumber;
        vol.name = name;
        vol.address = address;

        return is;
    }


    //output operator
    friend ostream& operator <<(ostream& os, volunteer vol){
        os<<vol.phoneNumber<<", "<<vol.address<<", "<<vol.phoneNumber<<endl;
        return os;
    }

};


#endif //Q2_VOLUNTEER_H
