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

class Solution
{
public:
    int countWays(vector<vector<int>> &ranges)
    {
        sort(ranges.begin(), ranges.end(),
             [](vector<int> num_pair1, vector<int> num_pair2)
             { return num_pair1[0] < num_pair2[0]; });

        int left = ranges[0][0], right = ranges[0][1];
        long long res = 2;

        for (int n = 0; n < ranges.size(); n++)
        {
            if (ranges[n][0] > right)
            {
                res *= 2;
                res %= (long long)1e9 + 7;
                left = ranges[n][0];
                right = ranges[n][1];
            }
            else
                right = max(right, ranges[n][1]);
        }

        return res;
    }
};



class Solution_
{
public:
    int countWays(vector<vector<int>> &ranges)
    {
        std::ios::sync_with_stdio(false);
        long long ans = 1;
        int max_r = -1;
        const int mod = 1e9 + 7;
        sort(ranges.begin(), ranges.end());
        for (auto r : ranges)
        {
            if (r[0] > max_r)
                ans = (ans << 1) % mod;
            max_r = max(max_r, r[1]);
        }
        return ans;
    }
};