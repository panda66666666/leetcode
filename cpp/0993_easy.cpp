#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
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

int prnt_x = 0, prnt_y = 0;
int X = 0, Y = 0;
int level_x = 0, level_y = 0;
void dfs(TreeNode *node, int prnt_val, int level)
{
    if (node->val == X)
    {
        prnt_x = prnt_val;
        level_x = level;
    }
    if (node->val == Y)
    {
        prnt_y = prnt_val;
        level_y = level;
    }

    if (node->left)
        dfs(node->left, node->val, level + 1);
    if (node->right)
        dfs(node->right, node->val, level + 1);

    return;
}

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        X = x;
        Y = y;
        dfs(root, 0, 0);
        return level_x == level_y && prnt_x != prnt_y;
    }
};