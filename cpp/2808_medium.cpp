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
    int minimumSeconds(vector<int> &nums)
    {
        int res = INT32_MAX;
        unordered_map<int, vector<int>> hash;
        for (int n = 0; n < nums.size(); n++)
        {
            if (hash.count(nums[n]))
                hash[nums[n]].push_back(n);
            else
                hash[nums[n]] = vector<int>({n});
        }

        for (auto iter = hash.begin(); iter != hash.end(); iter++)
        {
            iter->second.push_back(iter->second[0]);
            int tem_max = 0, index = 0;
            for (; index < iter->second.size() - 2; index++)
                tem_max =
                    max(tem_max, (iter->second[index + 1] - iter->second[index]) / 2);

            tem_max = max(tem_max, (int)(iter->second[index + 1] - iter->second[index] + nums.size()) / 2);
            res = min(res, tem_max);
        }

        return res;
    }
};
