#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

inline bool ifMatchK(int num, int &k)
{
    int bit_match_num = 0;
    while (num != 0)
    {
        bit_match_num += num % 2 == 1 ? 1 : 0;
        num /= 2;
    }
    return bit_match_num == k;
}

class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int res = 0;
        for (int n = 0; n < nums.size(); n++)
        {
            res += ifMatchK(n, k) ? nums[n] : 0;
        }
        return res;
    }
};