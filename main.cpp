#include <iostream>
#include "DVector.h"
#include "LinkedList.h"

int main() {
    std::cout << "Test linkedList:" << std::endl;

    LinkedList<int> linkedList;

    linkedList.pushFront(1);
    linkedList.pushFront(2);
    linkedList.pushFront(3);
    linkedList.pushFront(4);




    std::cout << "Size:"<<linkedList.getSize() << std::endl;


    for(int i=0;i<linkedList.getSize();i++){
        std::cout << "ValueAt("<<i<<")"
                  <<linkedList.valueAt(i)<< std::endl;
    }


    linkedList.reverse();
    for(int i=0;i<linkedList.getSize();i++){
        std::cout << "ValueAt("<<i<<")"
                  <<linkedList.valueAt(i)<< std::endl;
    }

    std::cout << "------------"<< std::endl;

    int bb=linkedList.popFront();
    bb++;

    std::cout << bb<< std::endl;

    for(int i=0;i<linkedList.getSize();i++){
        std::cout << "ValueAt("<<i<<")"
                  <<linkedList.valueAt(i)<< std::endl;
    }

   /* DVector<std::string> vector;

    vector.push("a1");
    vector.push("a2");
    vector.push("a3");
    vector.push("a4");
    vector.push("a5");
    vector.push("a6");
    vector.push("a7");
    vector.push("a8");
    vector.push("a9");

    std::cout << "Capacity:"<<vector.getCapacity()<< std::endl;
    for(int i=0;i<vector.getSize();i++){
        std::cout << vector.getValueAt(i) << std::endl;
    }*/




    return 0;
}