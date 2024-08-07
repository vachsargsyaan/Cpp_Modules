#pragma once

#include <iostream>

template <typename T>
class Array
{
    public:
        Array()
        {
            this->list = NULL;
            this->length = 0;
        }
        Array(unsigned int n)
        {
            this->list = new T[n];
            this->length = n;
        }
        Array( const Array<T>& copy ) : list(NULL)
           {
               if (this == &copy)
                   return ;
               (*this) = copy;
           }
        ~Array()
        {
            if (this->list)
                delete[] this->list;
        }
    public:
        Array<T>& operator=( const Array<T>& rhs )
        {
            if (this == &rhs)
                return (*this);

            if (this->list) {
                delete[] this->list;
                this->list = NULL;
            }

            unsigned int rhsSize = rhs.size();

            this->list = new T[rhsSize];
            for (unsigned int i = 0; i < rhsSize; i++)
                this->list[i] = rhs.list[i];
            this->length = rhsSize;
            return (*this);
        }
        T& operator[]( unsigned int index )
        {
            if (index >= this->size())
                throw std::runtime_error("Index is out of bounds!");
            return (this->list[index]);
        }

        const T& operator[]( unsigned int index ) const
        {
            if (index >= this->size())
                throw std::runtime_error("Index is out of bounds!");
            return (this->list[index]);
        }
    public:
        unsigned int size() const
        {
            return (this->length);
        }
    private:
        T* list;
        unsigned int length;
};