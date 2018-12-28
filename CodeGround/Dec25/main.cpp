
// main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>


void goodbye(const std::string &s) {
    std::cout << "Goodbye " << s << std::endl;
}

class Object {
public:
    void hello(const std::string &s) {
        std::cout << "Hello " << s << std::endl;
    }
};


int main() {

    {
        // lambda-introducer
        // lambda-parameter-declaration
        // lambda-return-type-clause
        // compound-statement
        auto func = [](const int &i) -> void { std::cout << "Hello, World!" << std::endl; };

        func(123);

        [](const int &i) -> void { std::cout << "Hello, World!" << std::endl; }(1234);

        {
            std::string name = "JackJack";
            [&]() { std::cout << name << std::endl; }();

            // lambda introducer [] 내부에 &를 사용하면 lambda function이
            // 정의된 영역 안에서 name을 reference로 사용할 수 있다.
            // [&name]도 가능하다.
            // 클래스의 멤버를 정의할 때는 [this]로 사용할 수도 있다.
            // [=] 이렇게 하면 name을 copy를 한다.
        }

        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);

        // auto func2 = [](int val) -> void { std::cout << val << std::endl; };
        auto func2 = [](int val) { std::cout << val << std::endl; };
        for_each(v.begin(), v.end(), func2);    // for_each in #include<algorithm>

        // 위와 같은 방법보다는 아래처럼 사용하는게 람다 함수의 취지에 부합.
        for_each(v.begin(), v.end(), [](int val) { std::cout << val << std::endl; });

        std::cout << []() -> int { return 1; }() << std::endl;

        // function pointer를 체계화 시켜줌. void는 return type, int는 parameter type.
        std::function<void(int)> func3 = func2;
        func3(123);

        // parameter가 없다. bind
        std::function<void()> func4 = std::bind(func3, 456);
        func4();

        // https://en.cppreference.com/w/cpp/utility/functional/placeholders
        {

            Object instance;
            // hello는 Object의 멤버 함수이므로 실행을 하려면 인스턴스가 필요하다. 패러미터 하나.
            auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

            f(std::string("World"));

            auto f2 = std::bind(&goodbye, std::placeholders::_1);
            f2(std::string("World"));

        }


    }


    return 0;
}


