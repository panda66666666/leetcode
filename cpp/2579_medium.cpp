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
    long long coloredCells(int n)
    {
        n = (long long)n;
        return (2 * n - 2) * (((2 * n - 4) / 2) + 1) + (2 * n - 1);
    }
};