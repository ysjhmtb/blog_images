#include <iostream>
#include <vector>

using namespace std;

class Fruit{
public:
    enum FruitType{
        APPLE,
        BANANA,
        CHERRY
    };

private:
    FruitType m_type;
    int m_percentageEaten = 0;

public:
    Fruit(FruitType type):
    m_type(type)
    {}

    FruitType getType(){return m_type;}
    int getPercenrageEaten(){return m_percentageEaten;}
};


int main() {

    Fruit apple(Fruit::APPLE);

    if(apple.getType() == Fruit::APPLE)
        cout << "I am an apple";
    else
        cout << "I am not an apple";

    return 0;

}