# Catch2 간단한 예시

<br>

1) [single header version](https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp) 을 `catch.hpp` 로 호출할 수 있어야 한다. 

<br>

2) 

```C++
unsigned int Factorial(unsigned int number) {
    return number > 1 ? Factorial(number - 1) * number : 1;
}
```

를 단위 테스트하고자 한다면

```C++

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

unsigned int Factorial(unsigned int number) {
    return number > 1 ? Factorial(number - 1) * number : 1;
}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
```

로 작성할 수 있다.

<br>

3) `#define CATCH_CONFIG_MAIN` 로 인해 프로젝트 내에 `main()` 가 존재하면 

```
duplicate symbol _main in:
    CMakeFiles/JanCpp.dir/main.cpp.o
    CMakeFiles/JanCpp.dir/testcase.cpp.o
```

에러가 발생한다.

<br>





