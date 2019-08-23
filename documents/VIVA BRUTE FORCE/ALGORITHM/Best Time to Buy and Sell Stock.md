```C++
/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Best Time to Buy and Sell Stock

*/

#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minV = numeric_limits<int>::max();
        int maxProfit = 0;
        for (const int &price : prices)
        {
            if (minV > price)
            {
                minV = price;
            }
            else
            {
                maxProfit = max(maxProfit, price - minV);
            }
        }

        return maxProfit;
    }
};

// clang++ -std=c++11 -g fourier.cpp -o fourier
int main()
{
    vector<int> ipt1 = {7, 1, 5, 3, 6, 4};  // 5
    vector<int> ipt2 = {7, 6, 4, 3, 1};     // 0

    Solution ref;
    cout << ref.maxProfit(ipt1) << endl;
    cout << ref.maxProfit(ipt2) << endl;

    return 0;
}
```

