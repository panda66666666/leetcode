#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        vector<int> dp(s.length() + 1, INT_MAX);
        unordered_map<string, int> map_s;
        for (auto str : dictionary)
        {
            map_s[str]++;
        }

        dp[0] = 0;
        for (int n = 1; n <= s.length(); n++)
        {
            dp[n] = dp[n - 1] + 1;
            for (int m = n - 1; m >= 0; m--)
            {
                if (map_s.count(s.substr(m, n - m)))
                {
                    dp[n] = min(dp[n], dp[m]);
                }
            }
        }

        return dp[s.length()];
    }
};
