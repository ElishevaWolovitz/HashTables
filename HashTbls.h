//
// Created by Gabi Bondi on 29/03/2022.
//
#include <iostream>
#ifndef Q2_HASHTBLS_H
#define Q2_HASHTBLS_H

using namespace std;

enum state {empty, full, deleted};
template <class T,class K>
class Item
{
public:
    T data;
    K key;
    state flag;
    Item(){}
    Item(T d, K k, state f){ data=d; key=k; flag=f;}
};


template <class T, class K>
class HashTbls {

public:
     Item<T,K>* item;
     int capacity;
     int tableSize;

     // constructor
     HashTbls();

    //constructor that accepts as a parameter the size of the table and initializes a table whose
    //size is the smallest prime number larger than the given size
    HashTbls(int n);

    //checks if a number is prime
    bool isPrime(int n);

    //destructor
    ~HashTbls();

    //hash function h1 that receives a key k of type K and returns its position in the table
    virtual int h1(K key) = 0;

    // probe function h2 which returns the step size
    virtual int h2(K key) = 0;

    //hash function
    double hash(K key,int i);

    //function insert which inserts an entry into the table
    int HashInsert(T data, K key);

    //function search which searches for an entry in the table
    int HashSearch(T data, K key);

    //function delete which deletes an entry from the table
    void HashDelete(T data, K key);


    //function print to display the contents of the entire table
    void print();

};


#endif //Q2_HASHTBLS_H
