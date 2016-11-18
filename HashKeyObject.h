//
// Created by vadimcg on 13.11.16.
//

#ifndef STRUCTURES_HASHKEYOBJECT_H
#define STRUCTURES_HASHKEYOBJECT_H

/**
 * Parent class for key-classes
 */
class   HashKeyObject{

public:
    virtual int hash()=0;

    bool  operator== (HashKeyObject  &a){
        return this->hash()==a.hash();
    }

    bool  operator== (HashKeyObject*  a){
        return this->hash()==a->hash();
    }

    virtual bool  isEmpty()=0;



};

#endif //STRUCTURES_HASHKEYOBJECT_H

