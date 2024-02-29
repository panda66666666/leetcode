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
    int maximumSwap(int num)
    {
        vector<int> v_num;
        while (num != 0)
        {
            v_num.push_back(num % 10);
            num /= 10;
        }
        reverse(v_num.begin(), v_num.end());
        vector<int> v_target = v_num;
        sort(v_target.begin(), v_target.end());
        reverse(v_target.begin(), v_target.end());
        for (int n = 0; n < v_num.size(); n++)
        {
            if (v_target[n] != v_num[n])
            {
                int m = v_num.size() - 1;
                for (; m >= 0; m--)
                {
                    if (v_num[m] == v_target[n])
                        break;
                }
                v_num[n] = v_num[n] + v_num[m];
                v_num[m] = v_num[n] - v_num[m];
                v_num[n] = v_num[n] - v_num[m];
                break;
            }
        }

        int res = 0;
        for (int bit : v_num)
        {
            res *= 10;
            res += bit;
        }
        return res;
    }
};

// 不排序的实现方法
class Solution_
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] < s[i + 1])
            {
                int j = i + 1, mx = j;
                while (j < n)
                {
                    if (s[j] >= s[mx])
                        mx = j;
                    ++j;
                }
                while (i - 1 >= 0 && s[i - 1] < s[mx])
                    --i;
                swap(s[i], s[mx]);
                break;
            }
        }
        return stoi(s);
    }
};