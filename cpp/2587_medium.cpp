#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <climits>
#include <numeric>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        vector<long> neg_nums;
        long pos_sum = 0, pos_num = 0;
        for (int &num : nums)
        {
            if (num > 0)
            {
                pos_num++;
                pos_sum += num;
            }
            else
            {
                neg_nums.push_back(num);
            }
        }
        sort(neg_nums.begin(), neg_nums.end(), [](int a, int b)
             { return a > b; });
        int res = pos_num;
        for (long &num : neg_nums)
        {
            pos_sum += num;
            if (pos_sum <= 0)
                break;

            res++;
        }

        return res;
    }
};