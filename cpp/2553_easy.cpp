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
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> res;
        function f = [&](int &a)
        {
            vector<int> tem;
            while (a != 0)
            {
                tem.push_back(a % 10);
                a /= 10;
            }
            for (int n = tem.size() - 1; n >= 0; n--)
                res.push_back(tem[n]);
        };

        for (int &num : nums)
            f(num);

        return res;
    }
};