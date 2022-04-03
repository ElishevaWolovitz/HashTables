//
// Created by Gabi Bondi on 29/03/2022.
//

#ifndef Q2_VOLUNTEER_H
#define Q2_VOLUNTEER_H
#include <string>
#include <iostream>
using namespace std;


class volunteer {

public:
    string name;
    string address;
    int phoneNumber;

public:

    volunteer(){
        name = "";
        address = "";
        phoneNumber = 0;
    }

    volunteer(string name, string address, int phoneNumber){
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
    }

    ~volunteer(){
        delete[] this;
    }

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
    }


    //output operator
    friend ostream& operator <<(ostream& os, volunteer vol){
        os<<vol.phoneNumber<<", "<<vol.address<<", "<<vol.phoneNumber<<endl;
        return os;
    };

};


#endif //Q2_VOLUNTEER_H
