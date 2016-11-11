//
// Created by vadimcg on 10.11.16.
//

#ifndef STRUCTURES_HASHTABLEOBJECT_H
#define STRUCTURES_HASHTABLEOBJECT_H

template<class T,class F>
class HashTableObject {

private:
    T key_;
    F value_;

public:
    HashTableObject(){
    }

    HashTableObject(HashTableObject * hashTableObject){
        this->key_=hashTableObject->key_;
        this->value_=hashTableObject->value_;
    }

    ~HashTableObject(){
    }

    T& getKey() const{
        return this->key_;
    }
    void setKey(const T& key){
        this->key_=key;
    }

    F& getValue() const{
        return this->value_;
    }
    void setValue(const F& value){
        this->value_=value;
    }

};


#endif //STRUCTURES_HASHTABLEOBJECT_H
