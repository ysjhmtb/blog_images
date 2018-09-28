#include <iostream>
#include <cstdlib>  // std::radn(), std::sranc()
#include <ctime>    // std::time()
#include <random>

using namespace std;


unsigned int PRNG() {
    // Pseudo Random Number Generator

    // static !!
    static unsigned int seed = 5523;    // seed number

    seed = 8253729 * seed + 2396403;
    return seed % 32768;

}


void printPRNG() {
    for (int count = 1; count <= 100; ++count) {
        cout << PRNG() << "\t";
        if (count % 5 == 0)
            cout << endl;
    }
}

void generateRDBwithoutTime() {
    // 디버깅 할 때는 시드를 고정해서 사용.
    std::srand(5323);   // seed

    for (int count = 1; count <= 100; ++count) {
        cout << std::rand() << "\t";
        if (count % 5 == 0)
            cout << endl;
    }
}


void generateRDNusingTime() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int count = 1; count <= 100; ++count) {
        cout << std::rand() << "\t";
        if (count % 5 == 0)
            cout << endl;
    }
}


int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (RAND_MAX + 1.0);

    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}


void generateRDNusingRandom() {
    // 가장 권장되는 방법. C++ 11 부터 가능.

    std::random_device rd;                      // 시간 대신 사용.
    std::mt19937 mesenne(rd());                 // create a mesenne twister
    std::uniform_int_distribution<> dice(1, 6);  // 1부터 6이 나올 확률이 동일.

    for (int count = 1; count <= 20; count++) {
        cout << dice(mesenne) << endl;
    }


}

void cpp59() {


    generateRDNusingRandom();
}