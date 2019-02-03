```C++


// C++ lambda

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //for_each
#include <functional>

void goodbye(const std::string &s)
{
    std::cout << "Goodbye " << s << std::endl;
}

class Object
{
  public:
    void hello(const std::string &s)
    {
        std::cout << "Hello " << s << std::endl;
    }
};

int main()
{

    // 1)

    // lambda introducer
    // lambda parameter declaration
    // lambda return type clause
    // compound statement
    auto func = [](const int &i) -> void { std::cout << "Hello, World" << std::endl; };

    // 실행
    func(123);

    // 실행
    [](const int &i) -> void { std::cout << "Hello, World" << std::endl; }(1234);

    // 2)

    {
        std::string name = "JackJack";
        [&]() { std::cout << name << std::endl; }();
        // [&]를 통해 name을 사용 가능. [&name]도 가능. 클래스의 멤버를 사용할 때는 [this] 가능. [=]를 사용하면 name을 복사함.
    }

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // 3)

    auto func2 = [](int val) { std::cout << val << std::endl; };
    for_each(v.begin(), v.end(), func2);

    // 이와 같이 사용할 수도 있지만 보다 람다 함수에 적합한 사용은 다음이다.

    for_each(v.begin(), v.end(), [](int val) { std::cout << val << std::endl; });

    // 4)

    // function pointer의 체계화
    std::function<void(int)> func3 = func2;
    func3(123);

    // 메개변수를 특정값으로 고정
    std::function<void(void)> func4 = std::bind(func3, 456);
    func4();

    // 5)
    {
        // https://en.cppreference.com/w/cpp/utility/functional/placeholders

        Object instance;

        auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);
        f(std::string("World"));

        auto f2 = std::bind(&goodbye, std::placeholders::_1);
        f2(std::string("World"));
    }

    return 0;
}
```

