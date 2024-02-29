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
    int alternatingSubarray(vector<int> &nums)
    {
        int res = -1, index = 0;
        while (index < nums.size() - 1)
        {
            if (nums[index + 1] - nums[index] == 1)
            {
                int flag = 1;
                int tem_res = 1;
                while (index < nums.size() - 1 && nums[index + 1] - nums[index] == flag)
                {
                    index++;
                    flag *= -1;
                    tem_res += 1;
                    res = max(res, tem_res);
                }
            }
            else
                index++;
        }

        return res;
    }
};
int main()
{
    vector<int> input = {2, 3, 4, 3, 4};
    Solution s;
    s.alternatingSubarray(input);
    return 0;
}