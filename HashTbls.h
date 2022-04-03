//
// Created by Gabi Bondi on 29/03/2022.
//
#pragma once
#include <iostream>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;

enum state {available, full, deleted };

template <class T, class K>
class Item
{
public:
    T data;
    K key;
    state flag = available;
    Item() {}
    Item(T d, K k, state f) { data = d; key = k; flag = f; }
};

template <class T, class K>
class HashTbls {

public:
    Item<T,K>* item;
    int capacity;
    int tableSize;

    // constructor
    HashTbls()
    {
        tableSize = 0;
        capacity = 0;
        item = new Item<T,K>[tableSize];
    }

    //constructor that accepts as a parameter the size of the table and initializes a table whose
    //size is the smallest prime number larger than the given size
    HashTbls(int n)
    {
        capacity = 0;
        tableSize = n + 1;
        while (!isPrime(tableSize)) {
            tableSize++;
        }
        //dynamically allocating item to an array of new tabel size
        item = new Item<T, K>[tableSize];
    }

    //checks if a number is prime
    bool isPrime(int n)
    {
        // Corner case
        if (n <= 1)
            return false;
        // Check from 2 to square root of n
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }

    //destructor
    ~HashTbls()
    {
        if (tableSize)
            delete[] item;
    }

    //hash function h1 that receives a key k of type K and returns its position in the table
    virtual int h1(K key) = 0;

    // probe function h2 which returns the step size
    virtual int h2(K key) = 0;

    //hash function
    double hash(K key, int i)
    {
        //linear Hash function

        return (((int)(key * tableSize) + i) % tableSize); //we have applied our own choice of h' function - h'(k) = floor(k*tablesize)
    }

    //function insert which inserts an entry into the table
    int HashInsert(T data, K key)
    {
        //initialize variables
        int i = 0;
        int hashValue;

        while (i != tableSize)
        {
            //calculate the hash value
            hashValue = hash(key, i);

            if (item[hashValue].flag != full)
            {
                item[hashValue].flag = full;
                item[hashValue].key = key;
                item[hashValue].data = data;
                capacity++;
                return hashValue;
            }
            else
            {
                i++;
            }
        }
        return NULL;

    }

    //function search which searches for an entry in the table
    int HashSearch(T data, K key)
    {
        // initialize variables
        int i = 0;
        int hashValue = 0;

        while (i != tableSize) {
            //calculate the hash value
            hashValue = hash(key, i);

            //if null it means the value is not in the tabel as not hashed too
            if (item[hashValue].flag == available) { //check if these was a not deleted and therefore must keep on looking
                return NULL;
            }
            else if (item[hashValue].key == key && item[hashValue].data == data)
            {
                return hashValue;
            }
            else
            {
                i++;
            }
        }
        throw "hash table overflow";
    }

    //function delete which deletes an entry from the table
    void HashDelete(T data, K key)
    {
        int i = 0;
        int hashValue = h1(key);

        while (i != tableSize) {
            //calculate the hash value
            hashValue = hash(key, i);

            //if null it means the value is not in the tabel as not hashed too
            if (item[hashValue].flag == available) { //check if these was a not deleted and therefore must keep on looking
                exit;
            }
            else if (item[hashValue].key == key) {
                item[hashValue].flag = deleted;
                item[hashValue].key = NULL;
                item[hashValue].data = NULL;
                capacity--;
            }
            else {
                i++;
            }
        }
    }


    //function print to display the contents of the entire table
    void print()
    {
        for (int i = 0; i < tableSize; i++) {
            if(item[i].flag == full)
                cout <<"at index "<< i << ":"<< item[i].data << " with key: " << item[i].key<< "\n";
        }
    }

};

