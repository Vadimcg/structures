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
    HashTableObject();
    HashTableObject(HashTableObject * hashTableObject);

    ~HashTableObject();

    T& getKey() const;
    void setKey(const T& key);

    F& getValue() const;
    void setValue(const F& value);

};


#endif //STRUCTURES_HASHTABLEOBJECT_H
