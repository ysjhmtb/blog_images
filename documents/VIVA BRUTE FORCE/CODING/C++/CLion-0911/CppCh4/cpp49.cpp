#include <iostream>
#include <vector>
#include <cstdint>

void cpp49() {

    using namespace std;

    /*
     * 만약에
     *
     * typedef double distance_t;
     *
     * 를
     *
     * typedef float distance_t;
     *
     * 으로 바꾸면
     *
     * distance_t  home2work;
     * distance_t  home2school;
     *
     * 에도 모두 적용된다.
     *
     */


    // type alias
    typedef double distance_t;

    double my_distance;
    distance_t home2work;
    distance_t home2school;



    // type alias
    // typedef vector<pair<string, int>> pairlist_t;
    using pairlist_t = vector<pair<string, int>>;

    pairlist_t pairlist1;
    pairlist_t pairlist2;


}

