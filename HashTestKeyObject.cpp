//
// Created by vadimcg on 15.11.16.
//

#include "HashTestKeyObject.h"


HashTestKeyObject::HashTestKeyObject(){
    this->key_=0;
}

HashTestKeyObject::HashTestKeyObject(int key){
    this->key_=key;
}
HashTestKeyObject::~HashTestKeyObject(){
}

int HashTestKeyObject::hash(){
    int x= this->key_;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}