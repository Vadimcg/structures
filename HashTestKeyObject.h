//
// Created by vadimcg on 15.11.16.
//

#include "HashKeyObject.h"

#ifndef STRUCTURES_HASHTESTOBJECT_H
#define STRUCTURES_HASHTESTOBJECT_H


class HashTestKeyObject :public HashKeyObject{

private:
     int key_;


public:
    HashTestKeyObject();

    HashTestKeyObject(int key);

    ~HashTestKeyObject();

    int hash();

    bool  isEmpty(){
        return this->key_==0;
    }
};


#endif //STRUCTURES_HASHTESTOBJECT_H
