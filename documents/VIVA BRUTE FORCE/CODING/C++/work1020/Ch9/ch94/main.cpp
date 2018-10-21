#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


using namespace std;

class Cents {
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }

    int getCents() const { return m_cents; };

    int &getCents() { return m_cents; }

    friend bool operator==(const Cents &c1, const Cents &c2) {
        return c1.m_cents == c2.m_cents;
    }

    friend bool operator<(const Cents &c1, const Cents &c2) {
        return c1.m_cents < c2.m_cents;
    }

    friend std::ostream &operator<<(std::ostream &out, const Cents &cents) {
        out << cents.m_cents;
        return out;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;


    Cents cents1(6);
    Cents cents2(6);

    if (cents1 == cents2)
        cout << "Equal" << endl;

    cout << std::boolalpha;


    vector<Cents> arr(20);
    for (unsigned i = 0; i < 20; ++i) {
        if (i == 19) {
            arr[i].getCents() = 1;
        } else {
            arr[i].getCents() = i;
        }
    }





    // std::random_shuffle(begin(arr), end(arr));

    std::sort(begin(arr), end(arr));

    for (auto &e : arr)
        cout << e << "  ";
    cout << endl;


    return 0;
}

/*
 * std::random_shuffle() 함수는 사용되지 않으며 std::shuffle()로 대체되었습니다.
 * 코드 예제 및 자세한 내용은 <random>과 Stackoverflow 게시물 std::random_shuffle 메서드가 C++14에서 사용되지 않는 이유를 참조하세요.
 *
 * https://msdn.microsoft.com/ko-kr/library/7dwe31kk.aspx
 */