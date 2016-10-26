//
// Created by vadimcg on 25.10.16.
//

#include <memory>
#include <iostream>
#ifndef STRUCTURES_DVECTOR_H
#define STRUCTURES_DVECTOR_H


class DVector {
private:
    const static int MIN_CAPACITY=12;

    std::unique_ptr<int[]> data_;
    int size_{0};
    int capacity_{MIN_CAPACITY};

    void ensureCapacity(int capacity);
    void increaseSize(int capacity);
    void decreaseSize(int capacity);

    void setNewCapacity();



public:
    DVector();
    DVector(const DVector& vector);
    ~DVector();

    int getSize() const;
    bool  isEmpty() const;
    int getCapacity()const;

    bool push(int value);
    int getValueAt(int index) const;
    bool deleteAt(int index);



};


#endif //STRUCTURES_DVECTOR_H
