//
// Created by Gabi Bondi on 29/03/2022.
//
#include <iostream>
#include <list>
#include "HashTbls.h"
using namespace std;

    //constructor that accepts as a parameter the size of the table and initializes a table whose
    //size is the smallest prime number larger than the given size
    template<class T, class K>
    HashTbls<T,K> :: HashTbls(int n) {
        int size = n + 1;
        while(!isPrime(size)){
            size++;
        }
        tableSize = size;
        Table.resize(tableSize);
    }

    //checks if a number is prime
    template<class T, class K>
    bool HashTbls<T,K> :: isPrime(int n){
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
    template<class T, class K>
    HashTbls<T,K> :: ~HashTbls() {
        ~Table;
    }

    template<class T, class K>
    double HashTbls<T,K> :: hash(K key,int i){
        //linear Hash function
        return (h1(item.key)+1)%tableSize;
    }

    template<class T, class K>
    int HashTbls<T,K> ::HashInsert(T data, K key){
        //initialize variables
        int i = 0;
        int hashValue;
        item(data, key, empty);

        while( i != tableSize ) {
            //calculate the hash value
            hashValue = hash(item.key, i);

            if(item.data[hashValue] == NULL || item.flag == deleted){
                item.flag = full;
                return hashValue;
            }
            else {
                i++;
            }
        }



    }

    //function insert which inserts an entry into the table
    template<class T, class K>
    int HashTbls<T,K> :: HashSearch(T data, K key){
        // initialize variables
        int i = 0;
        int hashValue = 0;

        while( i != tableSize ) {
            //calculate the hash value
            hashValue = hash(key, i);

            //if null it means the value is not in the tabel as not hashed too
            if(item.data[hashValue] == NULL && item.flag != deleted){ //check if these was a not deleted and therefore must keep on looking
                return NULL;
            }
            else if(item.data[hashValue] == key){
                item.flag = full;
                return hashValue;
            }
            else {
                i++;
            }
        }
        throw "hash table overflow";
    }

    //function delete which deletes an entry from the table
    template<class T, class K>
    void HashTbls<T,K> :: HashDelete(T data, K key){
        int i = 0;
        int hashValue = 0;

        while( i != tableSize ) {
            //calculate the hash value
            hashValue = hash(key, i);

            //if null it means the value is not in the tabel as not hashed too
            if(item.data[hashValue] == NULL && item.flag != deleted){ //check if these was a not deleted and therefore must keep on looking
                exit;
            }
            else if(item.data[hashValue] == key){
                item.flag = deleted;
                item.data[hashValue] = NULL;
            }
            else {
                i++;
            }
        }
    }

    //function print to display the contents of the entire table
    template<class T, class K>
    void HashTbls<T,K> :: print(){
        for (typename std::list<T>::iterator it=Table.begin(); it != Table.end(); ++it){
            cout << *it << ", "<< endl;
        }
    }


