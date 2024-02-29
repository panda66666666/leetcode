#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        int res = 0, words2_limit = words2.size() + 1;
        map<string, int> m;
        for (string word : words1)
            m[word] += m.count(word) ? words2_limit : 1;
        for (string word : words2)
            m[word]--;
        for (auto iter = m.begin(); iter != m.end(); iter++)
            if (iter->second == 0)
                res++;

        return res;
    }
};

// 这题我的解法比官方强，没必要看官方了
//  class Solution
//  {
//  public:
//      int countWords(vector<string> &words1, vector<string> &words2)
//      {
//          unordered_map<string, int> set;
//          unordered_map<string, int> set2;
//          int n = words1.size(), m = words2.size();
//          for (int i = 0; i < n; i++)
//          {
//              set[words1[i]]++;
//          }
//          int res = 0;
//          for (int i = 0; i < m; i++)
//          {
//              set2[words2[i]]++;
//          }
//          for (auto s : set)
//          {
//              if (s.second == 1 && set2[s.first] == 1)
//              {
//                  res++;
//              }
//          }
//          return res;
//      }
//  };