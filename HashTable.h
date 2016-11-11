//
// Created by vadimcg on 11.11.16.
//

#import <iostream>
#import "HashTableObject.h"

#ifndef STRUCTURES_HASHTABLE_H
#define STRUCTURES_HASHTABLE_H

template<class T,class F>
class HashTable {

private:
        HashTableObject* objects;
        int size_;
public:
        explicit HashTable(int size){

            if(size<=0){
                std::cout << "Incorrect size!" << std::endl;
                exit(EXIT_FAILURE);
            }

            this->size_=size;
            this->objects=new HashTableObject[size];
        }

};


#endif //STRUCTURES_HASHTABLE_H
