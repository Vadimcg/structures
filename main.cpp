#include <iostream>
#include "DVector.h"

int main() {
    std::cout << "Test vector:" << std::endl;

    DVector<std::string> vector;

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
    }
    return 0;
}