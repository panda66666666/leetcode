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

// class Solution
// {
// public:
//     bool validPartition(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> dp(n + 1, false);
//         dp[0] = true;
//         for (int i = 1; i <= n; i++)
//         {
//             if (i >= 2)
//             {
//                 dp[i] = dp[i - 2] && validTwo(nums[i - 2], nums[i - 1]);
//             }
//             if (i >= 3)
//             {
//                 dp[i] = dp[i] || (dp[i - 3] && validThree(nums[i - 3], nums[i - 2], nums[i - 1]));
//             }
//         }
//         return dp[n];
//     }

//     bool validTwo(int num1, int num2)
//     {
//         return num1 == num2;
//     }

//     bool validThree(int num1, int num2, int num3)
//     {
//         return (num1 == num2 && num1 == num3) || (num1 + 1 == num2 && num2 + 1 == num3);
//     }
// };

// 自己版本
class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        vector<bool> dp(nums.size() + 1, false);
        dp[0] = true;
        dp[1] = false;
        dp[2] = nums[0] == nums[1];
        if (nums.size() == 2)
            return dp[2];

        bool flag = false;
        for (int n = 3; n < nums.size() + 1; n++)
        {
            flag = false;
            if (dp[n - 2])
            {
                if (nums[n - 1] == nums[n - 2])
                {
                    flag = true;
                    dp[n] = true;
                }
            }
            if (dp[n - 3])
            {
                if ((nums[n - 1] == nums[n - 2] && nums[n - 2] == nums[n - 3]) ||
                    (nums[n - 1] == nums[n - 2] + 1 && nums[n - 1] == nums[n - 3] + 2))
                {
                    flag = true;
                    dp[n] = true;
                }
            }
            if (!flag)
                dp[n]=false;
        }

        return dp[nums.size()] ;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 4, 4, 5, 6};
    s.validPartition(nums);

    return 0;
}
