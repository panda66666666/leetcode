#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <set>
using namespace std;
inline int gussiSum(int begin, int end)
{
    return (begin + end) * (end - begin + 1) / 2;
}

class Solution
{
public:
    int minimumPossibleSum(int n, int target)
    {
        int flag1 = target / 2;
        if (flag1 >= n)
            return gussiSum(1, n) % (int)(1e9 + 7);
        else
            return (gussiSum(1, flag1) + gussiSum(target, target + (n - flag1 - 1))) % (int)(1e9 + 7);
    }
};