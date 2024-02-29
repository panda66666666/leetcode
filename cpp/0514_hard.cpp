#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <stack>
using namespace std;

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        vector<vector<vector<int>>> dp_hash(26);
        key = ring[0] + key;
        for (int n = 0; n < ring.size(); n++)
            dp_hash[ring[n] - 'a'].push_back({n, min((int)ring.size() - n, n)});

        for (int n = 1; n < key.size(); n++)
        {
            int cur_char_int = key[n] - 'a';
            int pre_char_int = key[n - 1] - 'a';
            for (int m = 0; m < dp_hash[cur_char_int].size(); m++)
            {
                int min_step = INT32_MAX;
                for (int i = 0; i < dp_hash[pre_char_int].size(); i++)
                    min_step = min(min_step,
                                   dp_hash[pre_char_int][i][1] +
                                       min(abs(dp_hash[cur_char_int][m][0] - dp_hash[pre_char_int][i][0]),
                                           (int)ring.size() - abs(dp_hash[cur_char_int][m][0] - dp_hash[pre_char_int][i][0])));

                dp_hash[cur_char_int][m][1] = min_step;
            }
        }

        int res = INT32_MAX;
        for (auto node : dp_hash[key[key.size() - 1] - 'a'])
        {
            res = min(res, node[1]);
        }

        return res + key.size() - 1;
    }
};

int main()
{
    string ring = "abcde", key = "ade";
    Solution s;
    cout << s.findRotateSteps(ring, key);
    return 0;
}