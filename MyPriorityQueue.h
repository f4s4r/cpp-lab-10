//
// Created by 4s4r on 19.01.2024.
//
#include <iostream>
#ifndef CPP_LAB_10_MYPRIORITYQUEUE_H
#define CPP_LAB_10_MYPRIORITYQUEUE_H

template <class T>
class MyPriorityQueue {
private:
    size_t size_;
    T* queue_;

public:
    //parameterless constructor
    MyPriorityQueue() : queue_(nullptr), size_(0) {}

    ~MyPriorityQueue()
    {
        delete[] this->queue_;
    }

    //methods
    size_t get_size() const
    {
        return this->size_;
    }


    void push(T item)
    {
        size_t start_size = this->get_size();
        T* temp = new T[start_size + 1];

        for (size_t i = 0; i < start_size; ++i) // copy current values to temp array
        {
            temp[i] = this->queue_[i];
//            if (item > this->queue_[i])
//            {
//                temp[i] = this->queue_[i];
//            }

        }
        temp[start_size] = item; // add extra block

        delete[] this->queue_;
        this->queue_ = new T[start_size + 1];

        for (size_t i = 0; i < start_size + 1; ++i)
        {
            this->queue_[i] = temp[i];
        }
        delete[] temp;

        this->size_ = this->get_size() + 1;
        this->show();
    }

    void show() const
    {
        std::cout << this->get_size() << " - cur size" << std::endl;
        if (this->get_size() != 0)
        {
            for (size_t i = 0; i < this->get_size(); ++i)
            {
                std::cout << this->queue_[i] << std::endl;
            }
        }
        else
        {
            std::cerr << "Zero array size" << std::endl;
        }
    }
};


#endif //CPP_LAB_10_MYPRIORITYQUEUE_H
