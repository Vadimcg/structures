//
// Created by vadimcg on 11.11.16.
//

#include <iostream>
#include "LinkedList.h"
#include "HashKeyObject.h"
#include "HashTableObject.h"

#ifndef STRUCTURES_HASHTABLE_H
#define STRUCTURES_HASHTABLE_H

template<class HashKeyObject,class F>
class HashTable {

private:

    LinkedList<HashTableObject<F>> * objects_;
    int size_;

    int getIndex(int hash){
        return abs(hash%size_);
    }

    void addWithNullKey(HashTableObject<F>* object){

    }


public:
    explicit HashTable(int size){

        if(size<=0){
            std::cout << "Incorrect size!" << std::endl;
            exit(EXIT_FAILURE);
        }

        this->size_=size;
        this->objects_=new LinkedList<HashTableObject<F>>[size];
    }

    void add(HashTableObject<F>* object){

        if(object->getKey()== nullptr){
            this->addWithNullKey(object);
            return;
        }

        int index=this->getIndex(object->getKey().hash());

        LinkedList<HashTableObject<F>>& list=this->objects_[index];

        for(int i=0;i<list.getSize();i++){
            if(list.valueAt(i).getKey()==object->getKey()){
               //if we found the same key, change value
               list.valueAt(i).setValue(object->getValue());
               return;
            }
        }

        list.pushFront(object);
    }


    ~HashTable(){
        delete[] objects_;
    }

};


#endif //STRUCTURES_HASHTABLE_H
