
#include <iostream>


namespace a {
    int my_var(10);
}

namespace b {
    int my_var(20);
}


void cpp43() {


    /*
     *  using namespace std; 대신
     *   using std::cout;    이런 사용도 가능하다.
     */


    using namespace std;

    {
        using namespace a;
        cout << my_var << endl;
    }


    {
        using namespace b;
        cout << my_var << endl;
    }


}