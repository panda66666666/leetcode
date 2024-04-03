#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
using namespace std;

string reverse_(string s)
{
    string s_ = s;
    reverse(s.begin(), s.end());
    return s;
}
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        return word.find(ch) == string::npos ? word : reverse_(word).substr(word.size() - word.find(ch) - 1) + word.substr(word.find(ch) + 1);
    }
};