#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return {};
        vector<vector<TreeNode *>> dp(n + 1);
        dp[1] = {new TreeNode(0)};
        for (int i = 3; i <= n; i += 2)
            for (int j = 1; j < i - 1; j += 2)
                for (TreeNode *&nodel : dp[j])
                    for (TreeNode *&noder : dp[i - 1 - j])
                    {
                        TreeNode *root = new TreeNode(0, nodel, noder);
                        dp[i].emplace_back(root);
                    }

        return dp[n];
    }
};