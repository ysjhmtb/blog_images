#include <iostream>

using namespace std;




class Fruit {

public:
    enum FruitType {
        APPLE, BANANA, CHERRY,
    };


private:
    FruitType m_type;

public:
    Fruit(FruitType type) : m_type(type) {}

    FruitType getType() { return m_type; }
};



void cpp814() {

    Fruit apple(Fruit::APPLE);

    if(apple.getType() == Fruit::APPLE)
    {
        cout << "Apple" << endl;
    }


}