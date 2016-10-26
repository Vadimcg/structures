//
// Created by vadimcg on 25.10.16.
//

#include "DVector.h"
DVector::DVector(){
    this->data_=std::unique_ptr<int[]>(new int[MIN_CAPACITY]);
}
DVector::DVector(const DVector& vector){

}
DVector::~DVector(){
    this->data_.reset();
}

int DVector::getSize() const{
    return this->size_;
}
bool  DVector::isEmpty() const{
    return size_==0;
}


int DVector::getCapacity() const{
    return this->capacity_;
}

bool DVector::push(int value){
    this->ensureCapacity(this->size_+1);
    this->data_[size_++]=value;
}

int DVector::getValueAt(int index) const{

    if(index>=size_ || index<0){
        std::cout << "Index out of bounds." << std::endl;
        exit(EXIT_FAILURE);
    }

    return this->data_[index];

}


bool DVector::deleteAt(int index) {

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

void  DVector::ensureCapacity(int capacity){
    if(capacity_<=capacity)
        this->increaseSize(capacity);
    else
        this->decreaseSize(capacity);


}

void DVector::increaseSize(int capacity){

    int new_capacity=this->capacity_;
    do {
         new_capacity =new_capacity*3/2+1;
    }while(new_capacity<capacity);

    capacity_=new_capacity;

    this->setNewCapacity();
}

void DVector::decreaseSize(int capacity){

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


void DVector::setNewCapacity(){
    std::unique_ptr<int[]> new_data(new int[capacity_]);

    for(int i=0;i<size_;i++){
        new_data[i]=data_[i];
    }

    data_=std::move(new_data);
}