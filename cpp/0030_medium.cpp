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
    int magicTower(vector<int> &nums)
    {
        long long flag = 1;
        for (int &num : nums)
            flag += (long long)num;

        if (flag <= 0)
            return -1;

        long long tem_hp = 1;
        priority_queue<int> pq;
        int res = 0;
        for (int &num : nums)
        {
            tem_hp = num + tem_hp;

            if (tem_hp <= 0)
            {
                res++;
                pq.emplace(-num);
                tem_hp += pq.top();
                pq.pop();
            }
            else if (num < 0)
            {
                pq.emplace(-num);
            }
        }

        return res;
    }
};