
// main.cpp

#include <iostream>
#include <string>
#include <vector>


int main() {

    {
        std::string str1("one");

        std::string str2;
        str2 = str1;
        str2 = "two";
        str2.assign("two").append(" three");
        std::cout << str2 << std::endl << std::endl;

    }

    {
        std::string str1("one");
        std::string str2("two");

        std::cout << str1 << " " << str2 << std::endl;
        std::swap(str1, str2);

        std::cout << str1 << " " << str2 << std::endl;

        str1.swap(str2);
        std::cout << str1 << " " << str2 << std::endl << std::endl;

        str1.append("three");
        str1.push_back('A');
        str1 += "three";

        std::cout << str1 << std::endl;

        str1 = str2 + " four";
        std::cout << str1 << std::endl << std::endl;
    }

    {
        std::string str("aaaa");
        str.insert(2, std::string("bbb"));

        std::cout << str << std::endl << std::endl;
    }

    return 0;
}


