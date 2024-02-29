#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

// 自己做法
// class Solution
// {
// public:
//     int addMinimum(string word)
//     {
//         int word_num = 0;
//         word += "c";
//         for (int n = 1; n < word.length(); n++)
//         {
//             if (word[n] <= word[n + 1])
//                 word_num++;
//         }
//         return word_num * 3 - word.length();
//     }
// };

// 扣友高效实现
// 要多用一下lambda表达式
class Solution
{
public:
    int addMinimum(string word)
    {
        size_t res = 0;
        auto get_or = [&word, &res](size_t &i, char c)
        {
            if (i == word.size())
                ++res;
            else if (word.at(i) < c)
                ++res;
            else if (word.at(i) > c)
                ++res;
            else
                ++i;
        };
        for (size_t i = 0; i < word.size();)
        {
            get_or(i, 'a');
            get_or(i, 'b');
            get_or(i, 'c');
        }
        return res;
    }
};