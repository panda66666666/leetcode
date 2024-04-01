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
    int minOperations(string s1, string s2, int x)
    {
        if (s1 == s2)
            return 0;
        vector<int> p;
        for (int n = 0; n < s1.size(); n++)
            if (s1[n] != s2[n])
                p.push_back(n);
        if (p.size() % 2 != 0)
            return -1;
        int f0 = 0, f1 = x;
        for (int n = 1; n < p.size(); n++)
        {
            int f_new = min(f1 + x, f0 + 2 * p[n] - 2 * p[n - 1]);
            f0 = f1;
            f1 = f_new;
        }
        return (int)(f1 / 2);
    }
};