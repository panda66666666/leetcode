#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        vector<int> pre_nums(nums.size(), 0), back_nums(nums.size(), 0);
        set<int> s;
        for (int n = 0; n < nums.size(); n++)
        {
            s.insert(nums[n]);
            pre_nums[n] = s.size();
        }
        s.clear();
        for (int n = nums.size() - 1; n >= 0; n--)
        {
            back_nums[n] = s.size();
            s.insert(nums[n]);
        }
        vector<int> res;
        for (int n = 0; n < nums.size(); n++)
            res.push_back(pre_nums[n] - back_nums[n]);

        return res;
    }
};

int main()
{
    vector<int> input = {1,
                         2,
                         3,
                         4,
                         5};
    Solution s;
    s.distinctDifferenceArray(input);
    return 0;
}