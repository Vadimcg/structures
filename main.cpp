#include <iostream>
#include <string>
#include "DVector.h"
#include "LinkedList.h"
#include "HashTable.h"
#include "HashTestKeyObject.h"

int main() {
    std::cout << "Test linkedList:" << std::endl;


    HashTable<HashTestKeyObject,std::string> hashTable=HashTable<HashTestKeyObject,std::string>(10);

    HashTestKeyObject key1(5);

    HashTableObject<std::string>* hashTableObject1=new HashTableObject<std::string>();
    hashTableObject1->setKey(key1);
    hashTableObject1->setValue("value1");


    hashTable.add(hashTableObject1);



    return 0;
}