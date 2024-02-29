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

vector<int> res;
inline void Dfs(TreeNode *node)
{
    if (!node)
        return;
    Dfs(node->left);

    Dfs(node->right);
    res.push_back(node->val);

    return;
}

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        res = vector<int>();
        Dfs(root);
        return res;
    }
};