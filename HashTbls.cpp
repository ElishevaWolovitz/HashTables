//
// Created by Gabi Bondi on 29/03/2022.
//
#include <iostream>
#include <list>
#include "HashTbls.h"
using namespace std;


    //default constructor
    template<class T, class K>
    HashTbls<T,K> :: HashTbls(){
        tableSize = 0;
        capacity = 0;
        item = new K;
        item->flag = empty;
    }

    //constructor that accepts as a parameter the size of the table and initializes a table whose
    //size is the smallest prime number larger than the given size
    template<class T, class K>
    HashTbls<T,K> :: HashTbls(int n) {
        capacity = 0; //not suer yet what it does
        tableSize = n + 1;
        while(!isPrime(tableSize)){
            tableSize++;
        }
        //dynamically allocating item to an array of tabel size
        item = new Item<T,K> [tableSize];  //might need to add is empty
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
        if (tableSize) delete [] item;
    }

    template<class T, class K>
    double HashTbls<T,K> :: hash(K key,int i){
        //linear Hash function
        return (h1(item->key)+i)%tableSize; //might need a pointer
    }

    template<class T, class K>
    int HashTbls<T,K> ::HashInsert(T data, K key){
        //initialize variables
        int i = 0;
        int hashValue;

        while( i != tableSize ) {
            //calculate the hash value
            hashValue = hash(key, i);

            if(item[hashValue] == NULL || item->flag == deleted){
                item->flag = full;
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
            if(item[hashValue] == NULL && item->flag != deleted){ //check if these was a not deleted and therefore must keep on looking
                return NULL;
            }
            else if(item[hashValue] == key){
                item->flag = full;
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
            if(item[hashValue] == NULL && item->flag != deleted){ //check if these was a not deleted and therefore must keep on looking
                exit;
            }
            else if(item[hashValue] == key){
                item->flag = deleted;
                item[hashValue] = NULL;
            }
            else {
                i++;
            }
        }
    }

    //function print to display the contents of the entire table
    template<class T, class K>
    void HashTbls<T,K> :: print(){
        for(int i = 0; i < tableSize; i++){
            cout<< item[i] << " " ;
        }
    }


