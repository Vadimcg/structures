//
// Created by vadimcg on 24.11.16.
//

#ifndef STRUCTURES_QUEUE_H
#define STRUCTURES_QUEUE_H

template<class T>
class Queue{

private:

    const int MIN_SIZE=10;
    unsigned int size_;

    T* queuePointer_;

    unsigned int start_;
    unsigned int end_;

    int amount_;


    void init(){
        this->queuePointer_ =new T[size_];
        this->start_=0;
        this->end_=size_-1;
        this->amount_=0;
    }

public:

    Queue():size_{MIN_SIZE}{
        this->init();
    }


    Queue(unsigned int size):size_{size}{
        this->init();
    }



    ~Queue(){
        delete[] queuePointer_;
    }


    void enqueue(T& element){

    }



};

#endif //STRUCTURES_QUEUE_H
