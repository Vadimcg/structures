#include <iostream>
#include "DVector.h"

int main() {
    std::cout << "Test vector:" << std::endl;

    DVector vector;


    for(int i=0;i<100;i++)
        vector.push(i);


    for(int i=99;i>15;i--)
        vector.deleteAt(i);


    std::cout << "Capacity:"<<vector.getCapacity()<< std::endl;
    for(int i=0;i<vector.getSize();i++){
        std::cout << vector.getValueAt(i) << std::endl;
    }

    return 0;
}