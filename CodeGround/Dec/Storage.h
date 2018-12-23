// Storage.h

#ifndef DEC_STORAGE_H
#define DEC_STORAGE_H

#include <iostream>

template<class T>
class Storage {
private:
    T m_value;

public:
    Storage(T value) {
        m_value = value;
    }

    ~Storage() {

    }

    void print() {
        std::cout << m_value << std::endl;
    }
};

// specialization
/*
 이 specialization이 Storage.cpp에 위치하면 제대로 기능하지 못한다.
 해결책이 몇 가지가 있다.

 1) 가장 좋은 방법은 그냥 Storage.h에 위치시키는 것이다. 요즘 C++ 오픈 소스들을 보면
    header only라고 적혀 있는 경우가 꽤 있다.

 2) main.cpp에서 #include "Storage.cpp"를 하는 방법도 있다. 

 */
template<>
void Storage<double>::print() {
    std::cout << "Double type ";
    std::cout << std::scientific << m_value << std::endl;
}

#endif //DEC_STORAGE_H
