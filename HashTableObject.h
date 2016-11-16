//
// Created by vadimcg on 10.11.16.
//

#ifndef STRUCTURES_HASHTABLEOBJECT_H
#define STRUCTURES_HASHTABLEOBJECT_H

template<class F>
class HashTableObject {

private:
    HashKeyObject* key_;
    F value_;

public:
    HashTableObject(){
    }

    HashTableObject(HashTableObject * hashTableObject){
        this->key_=hashTableObject->key_;
        this->value_=hashTableObject->value_;
    }

    ~HashTableObject(){
        delete key_;
    }

    HashKeyObject* getKey(){
        return this->key_;
    }
    void setKey(HashKeyObject* key){
        this->key_=key;
    }

    F& getValue(){
        return this->value_;
    }
    void setValue(const F& value){
        this->value_=value;
    }

};


#endif //STRUCTURES_HASHTABLEOBJECT_H
