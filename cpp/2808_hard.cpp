#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minimumTime(vector<int> &nums1, vector<int> &nums2, int x)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums1.size() + 1, 0));
        vector<pair<int, int>> nums(nums1.size());

        for (int n = 0; n < nums1.size(); n++)
            nums[n] = make_pair(nums2[n], nums1[n]);

        sort(nums.begin(), nums.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.first < b.first; });

        for (int n = 1; n <= nums.size(); n++)
            for (int m = 1; m <= nums.size(); m++)
                dp[n][m] = max(dp[n - 1][m], dp[n - 1][m - 1] + m * nums[n - 1].first + nums[n - 1].second);

        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);

        for (int n = 0; n <= nums.size(); n++)
            if (s1 + s2 * n - dp[nums.size()][n] <= x)
                return n;

        return -1;
    }
};

int main()
{
    vector<int> nums1({1, 2, 3}), nums2({1, 2, 3});
    Solution s;
    cout << s.minimumTime(nums1, nums2, 4);
    return 0;
}