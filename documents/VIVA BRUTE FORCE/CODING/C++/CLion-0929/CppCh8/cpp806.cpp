#include <iostream>

using namespace std;


class Simple806 {
private:
    int m_id;

public:
    Simple806(const int &id_in)
            : m_id(id_in) {
        cout << "Constructor " << m_id << endl;
    }

    ~Simple806() {
        cout << "Destructor " << m_id << endl;
    }

};


void cpp806() {

    /*
        Constructor 0
        Constructor 1
        Constructor 2
        Destructor 2
        Destructor 1
        Destructor 0
     */
    Simple806 s1(0);
    Simple806 s2(1);

    Simple806 *s3 = new Simple806(2);
    delete s3;




}


class IntArray806 {
private:
    int *m_arr = nullptr;   // vector 사용 추천.
    int m_length = 0;

public:
    IntArray806(const int length_in) {
        m_length = length_in;
        m_arr = new int[m_length];

        cout << "Constructor" << endl;
    }

    ~IntArray806() {
        cout << "Destructor" << endl;

        if(m_arr!=nullptr)
            delete[] m_arr;
    }

    int size() { return m_length; }
};


void cpp8061() {

    while(true){
        IntArray806(1000);
    }


}
