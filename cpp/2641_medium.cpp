#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <climits>
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

int level_tem = 0;
queue<pair<TreeNode *, int>> q;
vector<int> level_val_sum;
vector<int> level_val_list;

inline void Bfs(TreeNode *node, int level)
{
    q.emplace(node, 0);
    while (!q.empty())
    {
        auto n_l = q.front();
        q.pop();
        TreeNode *node_now = n_l.first;
        int level = n_l.second;
        // cout<<node_now->val<<' ';
        if (level > level_tem)
        {
            level_val_sum.push_back(accumulate(level_val_list.begin(), level_val_list.end(), 0));
            level_val_list = vector<int>();
            level_tem++;
        }

        level_val_list.push_back(node_now->val);
        if (node_now->left)
            q.emplace(node_now->left, level + 1);
        if (node_now->right)
            q.emplace(node_now->right, level + 1);
    }
    level_val_sum.push_back(accumulate(level_val_list.begin(), level_val_list.end(), 0));
}

inline void Dfs(TreeNode *node, int level)
{
    if (!node)
        return;
    int sum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
    if (node->left)
    {
        node->left->val = level_val_sum[level + 1] - sum;
        Dfs(node->left, level + 1);
    }
    if (node->right)
    {
        node->right->val = level_val_sum[level + 1] - sum;
        Dfs(node->right, level + 1);
    }
}

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        level_tem = 0;
        q = queue<pair<TreeNode *, int>>();
        level_val_sum = vector<int>();
        level_val_list = vector<int>();
        Bfs(root, 0);
        Dfs(root, 0);
        root->val = 0;
        return root;
    }
};
