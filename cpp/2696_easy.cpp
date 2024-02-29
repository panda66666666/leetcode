#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
// 自己实现
// class Solution
// {
// public:
//     int minLength(string s)
//     {

//         while (true)
//         {
//             bool flag = false;
//             for (int n = 0; n < s.length() - 1; n++)
//             {
//                 if (s.substr(n, 2) == "AB" || s.substr(n, 2) == "CD")
//                 {
//                     flag = true;
//                     s = s.substr(0, n) + s.substr(n + 2, s.length() - (n + 2));
//                     break;
//                 }
//             }

//             if (!flag || s.length() < 2)
//                 break;
//         }

//         return s.length();
//     }
// };

// constexpr static int a = 3;
// constexpr static int b = 4;

// 高效实现（栈实现，尬住了）
class Solution
{
public:
    int minLength(string s)
    {
        vector<int> st;
        for (char c : s)
        {
            st.push_back(c);
            int m = st.size();
            if (m >= 2 &&
                (st[m - 2] == 'A' && st[m - 1] == 'B' ||
                 st[m - 2] == 'C' && st[m - 1] == 'D'))
            {
                st.pop_back();
                st.pop_back();
            }
        }
        return st.size();
    }
};

int main()
{
    // constexpr int c = a + b;
    Solution s;
    string input = "CCCCDDDD";
    s.minLength(input);
    return 0;
}
