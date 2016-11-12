//
// Created by vadimcg on 11.11.16.
//

#import <iostream>
#include <typeinfo.h>
#import "HashTableObject.h"

#ifndef STRUCTURES_HASHTABLE_H
#define STRUCTURES_HASHTABLE_H

template<class T,class F>
class HashTable {

private:

    HashTableObject* objects;
    int size_;

    unsigned int makeHash(T key){

        unsigned int hash = 0;

        for (; *key; key++)
        {
            hash += (unsigned char)(*key);
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);

        return hash;
    }

public:
    explicit HashTable(int size){

        if(size<=0){
            std::cout << "Incorrect size!" << std::endl;
            exit(EXIT_FAILURE);
        }

        this->size_=size;
        this->objects=new HashTableObject[size];
    }


    ~HashTable(){
        delete[] objects;
    }














};


#endif //STRUCTURES_HASHTABLE_H
