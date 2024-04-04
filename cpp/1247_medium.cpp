#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int xy = 0, yx = 0;
        for (size_t n = 0; n < s1.size(); n++)
        {
            if (s1[n] == 'x' && s2[n] == 'y')
                xy++;
            else if (s1[n] == 'y' && s2[n] == 'x')
                yx++;
        }
        if ((xy + yx) % 2)
            return -1;
        return (xy / 2 + yx / 2) + 2 * (xy % 2);
    }
};