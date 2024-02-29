#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return true;
        else
        {
            int max_p = max(nums[0], nums[1]), max_pp = nums[0];
            for (int n = 2; n < nums.size(); n++)
            {
                if (nums[n] < max_pp)
                    return false;
                max_pp = max_p;
                max_p = max(nums[n], max_p);
            }
        }
        return true;
    }
};