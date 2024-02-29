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
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int n = 1; n < nums.size(); n++)
        {
            int tem = INT32_MIN;
            for (int m = 1; m <= k && n - m >= 0; m++)
                tem = max(tem, dp[n - m] + nums[n]);
            dp[n] = tem;
        }
        return dp[nums.size() - 1];
    }
};

// 加了个优先队列
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();

        // 优先队列中的二元组即为 (f[j], j)
        priority_queue<pair<int, int>> q;
        q.emplace(nums[0], 0);
        int ans = nums[0];

        for (int i = 1; i < n; ++i)
        {
            // 堆顶的 j 不满足限制
            while (i - q.top().second > k)
            {
                q.pop();
            }

            ans = q.top().first + nums[i];
            q.emplace(ans, i);
        }

        return ans;
    }
};
