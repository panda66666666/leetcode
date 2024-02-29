#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <climits>
#include <numeric>
using namespace std;

// 自己解法
// class Solution
// {
// public:
//     long long minimumRemoval(vector<int> &beans)
//     {
//         sort(beans.begin(), beans.end());
//         vector<long long> dp_min(beans.size(), 0), dp_max(beans.size(), 0);
//         long long series = 1;
//         long long res = LLONG_MAX;

//         for (int n = 1; n < beans.size(); n++)
//         {
//             if (beans[n] == beans[n - 1])
//             {
//                 dp_min[n] = dp_min[n - 1];
//                 series++;
//             }
//             else
//             {
//                 dp_min[n] = dp_min[n - 1] + series * beans[n - 1];
//                 series = 1;
//             }
//         }

//         for (int n = beans.size() - 1; n >= 0; n--)
//         {
//             dp_max[n] = dp_max[n + 1] + (beans.size() - n - 1) * (beans[n + 1] - beans[n]);
//         }

//         for (int n = 0; n < beans.size(); n++)
//             res = min(res, dp_max[n] + dp_min[n]);

//         return res;
//     }
// };


// 官方简单解法
class Solution
{
public:
    long long minimumRemoval(vector<int> &beans)
    {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0LL); // 豆子总数
        long long res = total;                                         // 最少需要移除的豆子数
        for (int i = 0; i < n; i++)
        {
            res = min(res, total - (long long)beans[i] * (n - i));
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> input = {4, 1, 6, 5};
    cout << s.minimumRemoval(input);
    return 0;
}
