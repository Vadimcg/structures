//
// Created by vadimcg on 25.10.16.
//

#include <memory>
#include <iostream>
#ifndef STRUCTURES_DVECTOR_H
#define STRUCTURES_DVECTOR_H


template<class T> class DVector {

private:
    const static int MIN_CAPACITY=12;

    std::unique_ptr<T[]> data_;
    int size_{0};
    int capacity_{MIN_CAPACITY};

    void ensureCapacity(int capacity){
        if(capacity_<=capacity)
            this->increaseSize(capacity);
        else
            this->decreaseSize(capacity);
    }

    void increaseSize(int capacity){
        int new_capacity=this->capacity_;
        do {
            new_capacity =new_capacity*3/2+1;
        }while(new_capacity<capacity);

        capacity_=new_capacity;

        this->setNewCapacity();
    }

    void decreaseSize(int capacity){
        int new_capacity=capacity_;
        if(capacity<capacity_/3){

            do{
                new_capacity=new_capacity/3*2+1;
            }while(new_capacity>capacity*3);

            if(new_capacity<MIN_CAPACITY)
                new_capacity=MIN_CAPACITY;

            capacity_=new_capacity;
            this->setNewCapacity();
        }
    }

    void setNewCapacity(){
        std::unique_ptr<T[]> new_data(new T[capacity_]);

        for(int i=0;i<size_;i++){
            new_data[i]=data_[i];
        }

        data_=std::move(new_data);
    }



public:

    DVector(){
        this->data_=std::unique_ptr<T[]>(new T[MIN_CAPACITY]);
    }

    DVector(const DVector& vector){

    }

    ~DVector(){
        this->data_.reset();
    }

    int getSize() const{
        return this->size_;
    }

    bool  isEmpty() const{
        return size_==0;
    }

    int getCapacity()const{
        return this->capacity_;
    }


    bool push(T value){
        this->ensureCapacity(this->size_+1);
        this->data_[size_++]=value;
    }

    T getValueAt(int index) const{
        if(index>=size_ || index<0){
            std::cout << "Index out of bounds." << std::endl;
            exit(EXIT_FAILURE);
        }

        return this->data_[index];
    }

    bool deleteAt(int index){
        if(index>=size_ || index<0){
            std::cout << "Index out of bounds." << std::endl;
            exit(EXIT_FAILURE);
        }

        this->decreaseSize(size_-1);

        for(int i=index;i<size_-1;i++){
            this->data_[i]=this->data_[i+1];
        }

        this->size_--;
    }


};


#endif //STRUCTURES_DVECTOR_H
