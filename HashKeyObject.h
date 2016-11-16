//
// Created by vadimcg on 13.11.16.
//

#ifndef STRUCTURES_HASHKEYOBJECT_H
#define STRUCTURES_HASHKEYOBJECT_H

/**
 * Parent class for key-classes
 */
class   HashKeyObject{

protected:
    int key_;

public:
    virtual int hash()=0;

    bool  operator== (HashKeyObject  &a){
        return this->hash()==a.hash();
    }

    virtual bool  isEmpty()=0;

    int getKey() const{
        return key_;
    }


};

#endif //STRUCTURES_HASHKEYOBJECT_H

