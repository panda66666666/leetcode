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
    int minIncrements(int n, vector<int> &cost)
    {
        int res = 0;
        for (int i = n - 1; i > 0; i -= 2)
        {

            if (i * 2 + 1 < n)
            {
                cost[i] += cost[i * 2 + 1];
                cost[i - 1] += cost[(i - 1) * 2 + 1];
            }
            res += max(cost[i], cost[i - 1]) - min(cost[i], cost[i - 1]);
            cost[i] = cost[i - 1] = max(cost[i], cost[i - 1]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> test = {1,
                        5,
                        2,
                        2,
                        3,
                        3,
                        1};
    cout << s.minIncrements(test.size(), test);
}