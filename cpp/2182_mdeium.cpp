#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

//自己实现
// class Solution
// {
// public:
//     string repeatLimitedString(string s, int repeatLimit)
//     {
//         int hash_alphet[26] = {0};
//         for (char c : s)
//             hash_alphet[c - 'a']++;

//         vector<pair<char, int>> v_s;
//         for (int n = 25; n >= 0; n--)
//         {
//             if (hash_alphet[n])
//                 v_s.push_back(make_pair(char('a' + n), hash_alphet[n]));
//         }

//         int index1 = 0, index2 = 1;
//         int series_alphet = 0;
//         string res = "";
//         while (true)
//         {
//             cout << index2;
//             if (series_alphet < repeatLimit && index1 < v_s.size())
//             {
//                 res += v_s[index1].first;
//                 v_s[index1].second--;
//                 series_alphet++;
//             }
//             else
//             {
//                 if (index2 >= v_s.size())
//                     break;
//                 res += v_s[index2].first;
//                 v_s[index2].second--;
//                 series_alphet = 0;
//             }

//             if (index2 < v_s.size() && !v_s[index2].second)
//                 index2++;
//             if (index1 < v_s.size() && !v_s[index1].second)
//             {
//                 index1 = index2;
//                 index2++;
//                 series_alphet = 0;
//             }
//         }

//         return res;
//     }
// };

//扣友高效实现
class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int a[26];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < s.size(); i++)
        {
            a[s[i] - 'a']++;
        }
        string ret;
        int num = 0;
        for (int i = 25, j = 24; i >= 0 && j >= 0;)
        {
            if (a[i] == 0)
            {
                num = 0;
                i--;
            }
            else if (num < repeatLimit)
            {
                a[i]--;
                ret.push_back('a' + i);
                num++;
            }
            else if (a[j] == 0 || j >= i)
            {
                j--;
            }
            else
            {
                a[j]--;
                ret.push_back('a' + j);
                num = 0;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    s.repeatLimitedString("aababab", 2);
    return 0;
}