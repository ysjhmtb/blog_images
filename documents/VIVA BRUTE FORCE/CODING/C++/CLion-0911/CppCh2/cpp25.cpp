///*
// 부동소수점 floating point
//
// 형 Type         최소 크기           전형적인 크기
// folat          4 바이트            4 바이트
// double         8 바이트            8 바이트
// Long double    8 바이트            8, 12, or 16 바이트
// */
//
//
//#include <iostream>
//#include <iomanip>
//#include <limits>
//#include <cmath>
//
//int main() {
//
//    using namespace std;
//
//    float f(3.141592f);         //3.14 = 31.4 * 0.1
//    double d(3.141592);
//    long double ld(3.141592);
//
//
//    cout << 3.14 << endl;
//    cout << 31.4e-1 << endl;
//    cout << 31.4e-2 << endl;
//    cout << 31.4e1 << endl;
//    cout << 31.4e2 << endl;
//    cout << "" << endl;
//
////    3.14
////    3.14
////    0.314
////    314
////    3140
//
//
//    cout << sizeof(float) << endl;
//    cout << sizeof(double) << endl;
//    cout << sizeof(long double) << endl;
//    cout << "" << endl;
//
////    4
////    8
////    16
//
//
//    cout << numeric_limits<float>::max() << endl;
//    cout << numeric_limits<double>::max() << endl;
//    cout << numeric_limits<long double>::max() << endl;
//    cout << "" << endl;
//
////    3.40282e+38
////    1.79769e+308
////    1.18973e+4932
//
//    cout << numeric_limits<float>::lowest() << endl;
//    cout << numeric_limits<double>::lowest() << endl;
//    cout << numeric_limits<long double>::lowest() << endl;
//    cout << "" << endl;
//
////    -3.40282e+38
////    -1.79769e+308
////    -1.18973e+4932
//
//
//    cout << std::setprecision(16) << endl;
//    cout << 1.0 / 3.0 << endl;
//    cout << "" << endl;
//
////    0.3333333333333333
//
//
//    cout << 0.1 << endl;
//    cout << std::setprecision(17);
//    cout << 0.1 << endl;
//    cout << "" << endl;
//
////    0.1
////    0.10000000000000001
//
//    double zero = 0.0;
//    double posinf = 5.0 / zero;
//    double neginf = -5.0 / zero;
//    double nan = zero / zero;
//
//    cout << posinf << " " << std::isinf(posinf) << endl;
//    cout << neginf << " " << std::isnan(neginf) << endl;
//    cout << nan << " " << std::isnan(nan) << endl;
//    cout << 1.0 << " " << std::isnan(1.0) << endl;
//
////    inf 1
////    -inf 0
////    nan 1
////    1 0
//
//
//    return 0;
//
//}