

#ifndef CLION_0929_CALA807_H
#define CLION_0929_CALA807_H

#include <iostream>


class Calc807 {

private:
    int m_value;

public:
    Calc807(int init_value);

    Calc807 &add(int value);

    Calc807 &sub(int value);

    Calc807 &mul(int value);

    void print();

};


#endif //CLION_0929_CALA807_H
