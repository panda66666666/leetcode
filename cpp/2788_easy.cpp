#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> res;
        string tem_str;
        for (string str : words)
        {
            for (char c : str)
            {
                if (c == separator)
                {
                    if (tem_str != "")
                    {
                        res.push_back(tem_str);
                        tem_str = "";
                    }
                }
                else
                {
                    tem_str += c;
                }
            }
            if (tem_str != "")
            {
                res.push_back(tem_str);
                tem_str = "";
            }
        }

        return res;
    }
};