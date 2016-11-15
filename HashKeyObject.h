//
// Created by vadimcg on 13.11.16.
//

#ifndef STRUCTURES_HASHKEYOBJECT_H
#define STRUCTURES_HASHKEYOBJECT_H

class   HashKeyObject{
public:
    virtual int hash(){
        return 0;
    };


    bool  operator== (HashKeyObject  &a){
        return this->hash()==a.hash();
    }

    bool virtual isEmpty(){
        return true;
    }
};

#endif //STRUCTURES_HASHKEYOBJECT_H

