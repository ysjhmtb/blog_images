
// AutoPtr.h

#ifndef DEC_AUTOPTR_H
#define DEC_AUTOPTR_H

#include <iostream>

// std::auto_ptr<int>;  C++ 98에서 등장, C++ 11 부터 사용하지 않기로 했고, C++ 17에서는 완전히 없애기로 함.


template<class T>

class AutoPtr {
public:
    T *m_ptr = nullptr;

public:
    AutoPtr(T *ptr = nullptr)
            : m_ptr(ptr) {
        std::cout << "AutoPtr default constructor" << std::endl;

    }

    ~AutoPtr() {

        std::cout << "AutoPtr destructor" << std::endl;
        if (m_ptr != nullptr) delete m_ptr;
    }


    AutoPtr(AutoPtr &a) {
        std::cout << "AutoPtr copy constructor" << std::endl;
//        m_ptr = a.m_ptr;
//        a.m_ptr = nullptr;

        // deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    AutoPtr &operator=(AutoPtr &a) {

        std::cout << "AutoPtr copy assignment " << std::endl;

        if (&a == this)
            return *this;

//        delete m_ptr;
//        m_ptr = a.m_ptr;
//        a.m_ptr = nullptr;
//        return *this;

        if (m_ptr != nullptr) delete m_ptr;

        // deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;

    }



    AutoPtr(AutoPtr &&a)
            : m_ptr(a.m_ptr) {
        a.m_ptr = nullptr;   // really necessary? 권장.
        std::cout << "AutoPtr move constructor" << std::endl;
    }

    AutoPtr &operator=(AutoPtr &&a) {
        std::cout << "AutoPtr move assignment" << std::endl;
        if (&a == this)
            return *this;

        if (!m_ptr) delete m_ptr;

        // shallow copy
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;   // really necessary? 권장.

        return *this;
    }


    T &operator*() const { return *m_ptr; }

    T *operator->() const { return m_ptr; }

    bool isNull() const { return m_ptr == nullptr; }
};

#endif //DEC_AUTOPTR_H
