#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <climits>
#include <numeric>
#include <queue>
using namespace std;

// 官方动态规划

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (i >= 2)
            {
                dp[i] = dp[i - 2] && validTwo(nums[i - 2], nums[i - 1]);
            }
            if (i >= 3)
            {
                dp[i] = dp[i] || (dp[i - 3] && validThree(nums[i - 3], nums[i - 2], nums[i - 1]));
            }
        }
        return dp[n];
    }

    bool validTwo(int num1, int num2)
    {
        return num1 == num2;
    }

    bool validThree(int num1, int num2, int num3)
    {
        return (num1 == num2 && num1 == num3) || (num1 + 1 == num2 && num2 + 1 == num3);
    }
};


