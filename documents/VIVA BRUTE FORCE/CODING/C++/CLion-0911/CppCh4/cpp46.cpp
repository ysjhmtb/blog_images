#include <iostream>
#include <string>
#include <limits>

void cpp46() {

    using namespace std;

    const char my_strs[] = "Hello, World";
    const string my_hello{"Hello, World"};
    string my_ID = "123";

    cout << my_hello << endl;

    cout << "Your name ? : ";
    string name;
//    cin >> name;
    std::getline(std::cin, name);

    cout << "Your age ? : ";
    string age;
//    cin >> age;
    std::getline(std::cin, age);


    cout << name << " " << age << endl;

}

void cpp46one() {

    using namespace std;

    cout << "Your age ? : ";
    int age;
    cin >> age;
    // \n을 만날 때까지 32767개의 글자를 무시해라.
    // std::cin.ignore(32767, '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Your name ? : ";
    string name;
    std::getline(std::cin, name);

    cout << name << " " << age << endl;
}


void cpp46two() {

    using namespace std;

    string a("Hello, ");
    string b("World");
    string hw = a + b;  // append

    hw += " I'm good";

    cout << hw << endl;
    cout << hw.length() << endl;


}



