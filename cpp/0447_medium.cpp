#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

// 自己的代码
// #define DISTANCE(x1, y1, x2, y2) pow((x2) - (x1), 2) + pow((y2) - (y1), 2)
// #define PAIR_SUM(x) x *(x - 1)

// class Solution
// {
// public:
//     int numberOfBoomerangs(vector<vector<int>> &points)
//     {
//         int res = 0;
//         const int len = points.size();
//         vector<std::vector<int>> dis_points(len, std::vector<int>(len, 0));
//         for (int n = 0; n < points.size(); n++)
//             for (int m = 0; m < points.size(); m++)
//                 dis_points[n][m] = DISTANCE(points[n][0], points[n][1], points[m][0], points[m][1]);

//         for (int n = 0; n < points.size(); n++)
//         {
//             map<int, int> dis_same_points;
//             for (int m = 0; m < points.size(); m++)
//                 dis_same_points[dis_points[n][m]] =
//                     dis_same_points.find(dis_points[n][m]) ==
//                             dis_same_points.end()
//                         ? 1
//                         : dis_same_points[dis_points[n][m]] + 1;

//             for (auto it = dis_same_points.begin(); it != dis_same_points.end(); it++)
//                 res += it->second >= 2 ? PAIR_SUM(it->second) : 0;
//         }

//         return res;
//     }
// };



// 扣友的高效版本
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<int> m(n);
        int total = 0;

        for (int centor = 0; centor < n; centor++)
        {
            int x = points[centor][0];
            int y = points[centor][1];
            for (int pos = 0; pos < n; pos++)
            {
                m[pos] = (points[pos][0] - x) * (points[pos][0] - x) +
                         (points[pos][1] - y) * (points[pos][1] - y);
            }

            sort(m.begin(), m.end());                         //如果一个数组可以从头开始更新，那么就不需要重新定义
            int ref = m[0];
            int count = 1;
            for (int t = 1; t < n; t++)
            {
                if (m[t] == ref)
                {
                    count++;
                }
                else
                {
                    if (count > 1)
                    {
                        total += count * (count - 1);
                        count = 1;
                    }
                }
                ref = m[t];
            }
            if (count > 1)
            {
                total += count * (count - 1);
            }
        }
        return total;
    }
};


int main()
{

    return 0;
}