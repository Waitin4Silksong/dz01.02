#pragma once
#include <iostream>
#include <string>

template <class T>
class Queue
{
private:
    T* data;
    int lenght;
public:
    Queue();
    explicit Queue(int size);
    Queue(const Queue<T>& queue);

    bool push_back(const T& value);
    bool pop();
    int size();
    bool empty();
    void swap(Queue<T>& other);
    
    friend std::ostream& operator << (std::ostream& out, const Queue<T>& queue)
    {
        for (size_t i = 0; i < queue.lenght; i++)
        {
            out << queue.data[i] << "\n";
        }
        return out;
    }
    Queue& operator=(const Queue<T>& other)
    {
        if (this != &other) {
            Queue<T> temp(other);
            swap(temp);
        }
        return *this;
    }
    ~Queue()
    {
        delete[] data;
    }

};

template<class T>
inline Queue<T>::Queue() : data{ nullptr }, lenght{ 0 }
{
}

template<class T>
inline Queue<T>::Queue(int size) : lenght{ size }, data{ new T[size] }
{
}

template<class T>
inline Queue<T>::Queue(const Queue<T>& queue) : lenght{ queue.lenght }, data{ new T[queue.lenght] }
{
    for (size_t i = 0; i < queue.lenght; i++)
    {
        data[i] = queue.data[i];
    }
}

template<class T>
inline bool Queue<T>::push_back(const T& value)
{
    T* temp = new T[lenght + 1];
    for (size_t i = 0; i < lenght; i++)
    {
        temp[i] = data[i];
    }

    temp[lenght] = value;
    lenght++;

    delete[] data;
    data = temp;
    return true;
}


template<class T>
inline bool Queue<T>::pop()
{
    if (lenght > 0)
    {
        T* temp = new T[lenght - 1];
        for (size_t i = 0; i < lenght - 1; i++)
        {
            temp[i] = data[i + 1];
        }
        delete[] data;
        data = temp;
        lenght--;
        return true;
    }
    else 
    {
        return false;
    }

}

template<class T>
inline int Queue<T>::size()
{
    return lenght;
}

template<class T>
inline bool Queue<T>::empty()
{
    return lenght > 0 ? false : true;
}

template<class T>
inline void Queue<T>::swap(Queue<T>& other)
{
    std::swap(lenght, other.lenght);
    std::swap(data, other.data);
}

