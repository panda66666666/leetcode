#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(string str1, string str2)
{
    for (int n = 0; n < str1.size(); n++)
        if (str1[n] != str2[str2.size() - n - 1])
            return false;
    return true;
}

class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int res = 0;
        vector<bool> if_matched(words.size(), false);
        for (int n = 0; n < words.size() - 1; n++)
        {
            if (if_matched[n])
                continue;
            for (int m = n + 1; m < words.size(); m++)
            {
                if (cmp(words[n], words[m]))
                {
                    if_matched[m] = true;
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};

