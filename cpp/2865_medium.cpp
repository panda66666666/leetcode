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
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        long long res = 0, tem_sum = 0;
        vector<long long> heights(maxHeights.size(), 0);
        for (int n = 0; n < maxHeights.size(); n++)
        {
            heights[n] = maxHeights[n];
            tem_sum = heights[n];
            for (int m = n - 1; m >= 0; m--)
            {
                heights[m] = min((long long)maxHeights[m], heights[m + 1]);
                tem_sum += heights[m];
            }
            for (int m = n + 1; m < maxHeights.size(); m++)
            {
                heights[m] = min((long long)maxHeights[m], heights[m - 1]);
                tem_sum += heights[m];
            }
            res = max(res, tem_sum);
        }

        return res;
    }
};

// 单调栈解法
class Solution_
{
public:
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        int n = maxHeights.size();
        long long res = 0;
        vector<long long> prefix(n), suffix(n);
        stack<int> stack1, stack2;

        for (int i = 0; i < n; i++)
        {
            while (!stack1.empty() && maxHeights[i] < maxHeights[stack1.top()])
            {
                stack1.pop();
            }
            if (stack1.empty())
            {
                prefix[i] = (long long)(i + 1) * maxHeights[i];
            }
            else
            {
                prefix[i] = prefix[stack1.top()] + (long long)(i - stack1.top()) * maxHeights[i];
            }
            stack1.emplace(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stack2.empty() && maxHeights[i] < maxHeights[stack2.top()])
            {
                stack2.pop();
            }
            if (stack2.empty())
            {
                suffix[i] = (long long)(n - i) * maxHeights[i];
            }
            else
            {
                suffix[i] = suffix[stack2.top()] + (long long)(stack2.top() - i) * maxHeights[i];
            }
            stack2.emplace(i);
            res = max(res, prefix[i] + suffix[i] - maxHeights[i]);
        }
        return res;
    }
};
