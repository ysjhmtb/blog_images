#include <iostream>
#include <vector>

using namespace std;

void cpp7111() {

    std::vector<int> v{1, 2, 3};
    // vector에는 size와 capacity가 있다. 내부적으로는 capacity만큼 메모리를 가지고 있다.
    // size는 그중에서 실제 사용하는 수.

    v.resize(2);
    // v.reserve(1024);

    for (auto &e : v)
        cout << e << " ";
    cout << endl;

    cout << v.size() << "   " << v.capacity() << endl;


}


void printStack7112(const std::vector<int> &stack) {

    for (auto &e:stack)
        cout << e << " ";
    cout << endl;
}

void cpp7112() {

    std::vector<int> stack;

    /*
        3
        3 5
        3 5 7
        3 5
        3
     */

    stack.push_back(3);
    printStack7112(stack);

    stack.push_back(5);
    printStack7112(stack);

    stack.push_back(7);
    printStack7112(stack);

    stack.pop_back();
    printStack7112(stack);

    stack.pop_back();
    printStack7112(stack);

    stack.pop_back();
    printStack7112(stack);


}

