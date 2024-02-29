#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

inline bool ifMatch(vector<int> &nums, int &limit, int &k)
{
    int tokens_num = 0, tem_sum = 0;
    for (int num : nums)
    {
        if (tem_sum + num > limit)
        {
            tokens_num++;
            tem_sum = num;
        }
        else
            tem_sum += num;
    }
    tokens_num += tem_sum != 0 ? 1 : 0;
    return tokens_num <= k;
}


class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0);
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (ifMatch(nums, mid, k))
                r = mid;
            else
                l = mid + 1;
        }

        return r;
    }
};

int main()
{
    Solution s;
    vector<int> nums({7, 2, 5, 10, 8});
    int k = 2;
    s.splitArray(nums, k);
    return 0;
}