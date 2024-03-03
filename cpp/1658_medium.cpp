#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        if (accumulate(nums.begin(), nums.end(), 0) < x)
            return -1;
        else
        {
            unordered_map<int, int> m_rev;
            vector<int> v_acc_pre;
            int acc_pre, acc_rev = 0;
            v_acc_pre.push_back(0);
            m_rev[0] = 0;
            for (int n = 0; n < nums.size(); n++)
            {
                acc_pre += nums[n];
                acc_rev += nums[nums.size() - 1 - n];
                v_acc_pre.push_back(acc_pre);
                m_rev[acc_rev] = n + 1;
            }

            int res = INT32_MAX;
            for (int n = 0; n <= nums.size(); n++)
            {
                if (m_rev.count(x - v_acc_pre[n]))
                    res = min(res, n + m_rev[x - v_acc_pre[n]]);
                else if (x - v_acc_pre[n] < 0)
                    break;
            }

            return res == INT32_MAX ? -1 : res;
        }
    }
};

// 滑动窗口更快
class Solution_
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < x)
        {
            return -1;
        }

        int right = 0;
        int lsum = 0, rsum = sum;
        int ans = n + 1;

        for (int left = -1; left < n; ++left)
        {
            if (left != -1)
            {
                lsum += nums[left];
            }
            while (right < n && lsum + rsum > x)
            {
                rsum -= nums[right];
                ++right;
            }
            if (lsum + rsum == x)
            {
                ans = min(ans, (left + 1) + (n - right));
            }
        }

        return ans > n ? -1 : ans;
    }
};

int main()
{
    vector<int> test = {1,
                        1,
                        4,
                        2,
                        3};
    int x = 5;
    Solution s;
    cout << s.minOperations(test, x);
    return 0;
}
