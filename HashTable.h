//
// Created by vadimcg on 11.11.16.
//

#include <iostream>
#include "HashKeyObject.h"
#include "HashTableObject.h"

#ifndef STRUCTURES_HASHTABLE_H
#define STRUCTURES_HASHTABLE_H

template<class HashKeyObject,class F>
class HashTable {

private:

    HashTableObject<F>* objects_;
    int size_;

    int getIndex(int hash){
        return abs(hash%size_);
    }

public:
    explicit HashTable(int size){

        if(size<=0){
            std::cout << "Incorrect size!" << std::endl;
            exit(EXIT_FAILURE);
        }

        this->size_=size;
        this->objects_=new HashTableObject<F>[size];

        for(int i=0;i<this->size_;i++){
            this->objects_[i].setKey(nullptr);
        }
    }

    void add(HashTableObject* object){
        int index=this->getIndex(object->getKey().hash());

    }


    ~HashTable(){
        delete[] objects_;
    }

};


#endif //STRUCTURES_HASHTABLE_H
