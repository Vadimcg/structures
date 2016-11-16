#include <iostream>
#include <string>
#include "DVector.h"
#include "LinkedList.h"
#include "HashTable.h"
#include "HashTestKeyObject.h"

int main() {
    std::cout << "Test linkedList:" << std::endl;


    HashTable<HashTestKeyObject,std::string> hashTable=HashTable<HashTestKeyObject,std::string>(10);

    HashTestKeyObject* key1=new HashTestKeyObject(5);
    HashTableObject<std::string>* hashTableObject1=new HashTableObject<std::string>();
    hashTableObject1->setKey(key1);
    hashTableObject1->setValue("value1");


    HashTestKeyObject* key2=new HashTestKeyObject(1);
    HashTableObject<std::string>* hashTableObject2=new HashTableObject<std::string>();
    hashTableObject2->setKey(key2);
    hashTableObject2->setValue("value2");


    HashTestKeyObject* key3=new HashTestKeyObject(5);
    HashTableObject<std::string>* hashTableObject3=new HashTableObject<std::string>();
    hashTableObject3->setKey(key3);
    hashTableObject3->setValue("value3");


    hashTable.add(hashTableObject1);
    hashTable.add(hashTableObject2);
    hashTable.add(hashTableObject3);

    HashTableObject<std::string> mm=hashTable.get(key3);



    return 0;
}