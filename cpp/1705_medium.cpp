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
    vector<string> findLongestSubarray(vector<string> &array)
    {
        vector<int> dp(array.size(), 0);
        map<int, int> map_index;
        map_index[0] = -1;
        int alphabet = 0, number = 0;
        int res_index = -1, res_length = 0;
        for (int n = 0; n < array.size(); n++)
        {
            if (((size_t)array[n][0] >= 'A' && (size_t)array[n][0] <= 'Z') || ((size_t)array[n][0] >= 'a' && (size_t)array[n][0] <= 'z'))
                alphabet++;
            else
                number++;
            dp[n] = alphabet - number;
            if(array[n]=="52")
                auto useless = 0;
            if (!map_index.count(dp[n]))
                map_index[dp[n]] = n;
            if (map_index.count(dp[n]))
            {
                res_index = res_length >= n - map_index[dp[n]] ? res_index : n;
                res_length = max(res_length, n - map_index[dp[n]]);
            }
        }

        return vector<string>(array.begin() + res_index + 1 - res_length, array.begin() + res_index + 1);
    }
};

int main()
{
    Solution s;
    vector<string> test = {"42", "10", "O", "t", "y", "p", "g", "B", "96", "H", "5", "v", "P", "52", "25", "96", "b", "L", "Y", "z", "d", "52", "3", "v", "71", "J", "A", "0", "v", "51", "E", "k", "H", "96", "21", "W", "59", "I", "V", "s", "59", "w", "X", "33", "29", "H", "32", "51", "f", "i", "58", "56", "66", "90", "F", "10", "93", "53", "85", "28", "78", "d", "67", "81", "T", "K", "S", "l", "L", "Z", "j", "5", "R", "b", "44", "R", "h", "B", "30", "63", "z", "75", "60", "m", "61", "a", "5", "S", "Z", "D", "2", "A", "W", "k", "84", "44", "96", "96", "y", "M"};
    auto x = s.findLongestSubarray(test);
    std::cout << "hhh";
    return 0;
}