//
// Created by 4s4r on 19.01.2024.
//
#include <iostream>
#ifndef CPP_LAB_10_MYPRIORITYQUEUE_H
#define CPP_LAB_10_MYPRIORITYQUEUE_H

template <typename T>
class MyPriorityQueue {
private:
    size_t size_;
    T* queue_;

public:
    //parameterless constructor
    MyPriorityQueue() : queue_(nullptr), size_(0) {}

    MyPriorityQueue(const MyPriorityQueue& other) : size_(other.get_size())
    {
        //delete[] queue_;
        queue_ = new T[other.get_size()];
        for (size_t i = 0; i < other.get_size(); ++i)
        {
            queue_[i] = other.queue_[i];
        }
    }

    ~MyPriorityQueue()
    {
        delete[] queue_;
        size_ = 0;
    }



    //methods
    size_t get_size() const
    {
        return this->size_;
    }


    void copy_t(const T* other, size_t new_size)
    {
        delete[] queue_;
        queue_ = new T[new_size];
        for (size_t i = 0; i < new_size; ++i)
        {
            queue_[i] = other[i];
        }
        size_ = new_size;
    }

    void resize(size_t new_size)
    {
        T* temp = new T[new_size];
        for (size_t i = 0; i < this->get_size(); ++i)
        {
            temp[i] = queue_[i];
        }
        delete[] queue_;
        queue_ = new T[new_size];
        for (size_t i = 0; i < new_size; ++i)
        {
            queue_[i] = temp[i];
        }
        queue_[new_size] = 0;
        size_ = new_size;
    }

    void push(T item) {
        size_t start_size = this->get_size();

        if (start_size == 0 || item >= queue_[start_size - 1]) {
            // push in end or empty queue
            this->resize(start_size + 1);
            queue_[start_size] = item;
        }
        else
        {
            // searching for place for insert
            size_t i;
            T* temp = new T[start_size + 1];

            for (size_t j = 0; j < start_size; ++j)
            {
                temp[j] = queue_[j]; // copying queue in temp
            }

            for (i = start_size; i > 0 && item < queue_[i - 1]; --i)
            {
                temp[i] = queue_[i - 1]; // shifting
            }
            temp[i] = item;
            this->copy_t(temp, start_size + 1);

        }
        this->show();
    }


    T pop(size_t index = SIZE_MAX)
    {
        size_t start_size = this->get_size();
        if (index == SIZE_MAX)
        {
            T res = queue_[start_size - 1];
            this->resize(start_size - 1);

            this->show();

            return res;
        }
        else
        {
            T res = queue_[index];
            T* temp = new T[start_size - 1];
            for (size_t i = 0; i < start_size - 1; ++i)
            {
                if (i < index)
                    temp[i] = queue_[i];
                else
                    temp[i] = queue_[i+1];
            }
            this->copy_t(temp, start_size - 1);

            this->show();

            return res;
        }
    }

    T peek(size_t index)
    {
        return queue_[index];
    }

    size_t size()
    {
        return this->get_size(); // -_-
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
    friend std::ostream &operator<<(std::ostream &os, const MyPriorityQueue<T> &pq);
};
template <typename T>
std::ostream &operator<<(std::ostream &os, const MyPriorityQueue<T> &pq)
{
    for (size_t i = 0; i < pq.get_size(); ++i)
    {
        os << pq.queue_[i] << " ";
    }
    return os;
}

#endif //CPP_LAB_10_MYPRIORITYQUEUE_H
