
// MyArray.h

#ifndef DEC_MYARRAY_H
#define DEC_MYARRAY_H

#include <assert.h>
#include <iostream>


template<typename T, unsigned int T_SIZE>


class MyArray {
private:
    // T m_length;
    T *m_data;  // T m_data[T_SIZE]

public:
    MyArray() {
        m_data = new T[T_SIZE];
    }


    ~MyArray() {
        delete[] m_data;
    }


    T &operator[](int index) {
        assert(index >= 0 && index < T_SIZE);
        return m_data[index];
    }

    int getLength() {
        return T_SIZE;
    }

    // T_SIZE로 어떤 숫자든지 들어올 수 있다. 따라서 MyArray.cpp에서 이 함수를 정의한 후
    // explicit instantiation 하기가 어렵다. 그래서 non type parameter를 사용하는 경우에는
    // 전부 header에 집어 넣는다.
    void print() {
        for (int i = 0; i < T_SIZE; ++i)
            std::cout << m_data[i] << std::endl;
        std::cout << std::endl;
    };
};


#endif //DEC_MYARRAY_H
