
// 따배씨++ 3.9 비트 플래그, 비트 마스크 사용법 Bit flags, Bit masks

#ifndef CLION_0911_CPP39_H
#define CLION_0911_CPP39_H

#include <iostream>
#include <bitset>

void execFunc() {

    using namespace std;

    /*
     *  이렇게 사용하려면 번거로움.
     *
     *
        bool item1_flag = false;
        bool item2_flag = false;
        bool item3_flag = false;
        bool item4_flag = false;

        // event!
        item1_flag = true;

        // die! item2 los
        item2_flag = false;

        if (item3_flag == true) {
            // event

        }

        if (item3_flag == true && item4_flag == false) {
            item3_flag = false;
            item4_flag = true;
        }
     */

    const unsigned char opt0 = 1 << 0;
    const unsigned char opt1 = 1 << 1;
    const unsigned char opt2 = 1 << 2;
    const unsigned char opt3 = 1 << 3;

    cout << bitset<8>(opt0) << endl;
    cout << bitset<8>(opt1) << endl;
    cout << bitset<8>(opt2) << endl;
    cout << bitset<8>(opt3) << endl;

    cout << "\n\n" << endl;

    unsigned char items_flag = 0;

    cout << "No item" << bitset<8>(items_flag) << endl;

    // item0 on
    items_flag |= opt0;
    cout << "item0 obtained : " << bitset<8>(items_flag) << endl;

    // item3 on
    items_flag |= opt3;
    cout << "item3 obtained : " << bitset<8>(items_flag) << endl;

    // item3 lost
    items_flag &= ~opt3;
    cout << "item3 obtained : " << bitset<8>(items_flag) << endl;

    // has item1 ?
    if (items_flag & opt1) {
        cout << "Has item1 " << endl;
    } else { cout << "Not have item1" << endl; }

    // has item0 ?
    if (items_flag & opt0) {
        cout << "Has item0 " << endl;
    }

    // obtain item 2, 3
    items_flag |= (opt2 | opt3);
    cout << bitset<8>(opt2 | opt3) << endl;
    cout << "item2, 3 obtained " << bitset<8>(items_flag) << endl;


    if ((items_flag & opt2) && !(items_flag & opt1)) {
        items_flag ^= opt2;
        items_flag ^= opt1;
    }

    cout << bitset<8>(items_flag) << endl;


}


void execFunc1() {

    using namespace std;

    const unsigned int red_mask = 0xFF0000;
    const unsigned int green_mask = 0x00FF00;
    const unsigned int blue_mask = 0x0000FF;

    cout << bitset<32>(red_mask) << endl;
    cout << bitset<32>(green_mask) << endl;
    cout << bitset<32>(blue_mask) << endl;

    unsigned int pixel_color = 0xDAA520;

    // 0x 00DAA520
    // 0000 0000 1101 1010 1010 0101 0010 0000
    cout << bitset<32>(pixel_color) << endl;


    unsigned char red = (pixel_color & red_mask) >> 16;
    unsigned char green = (pixel_color & green_mask) >> 8;
    unsigned char blue = pixel_color & blue_mask;

    cout << "red " << bitset<8>(red) << " " << int(red) << endl;
    cout << "green " << bitset<8>(green) << " " << int(green) << endl;
    cout << "blue " << bitset<8>(blue) << " " << int(blue) << endl;


}

#endif //CLION_0911_CPP39_H
