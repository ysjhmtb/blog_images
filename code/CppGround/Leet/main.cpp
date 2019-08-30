
#include "medianOfTwoSortedArrays.h"

int main() {

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};

    Solution ref;
    cout << ref.findMedianSortedArrays(nums1, nums2) << endl;
    cout << ref.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}