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
void Dfs(TreeNode* node)
{
    if(node->left)
        Dfs(node->left);
    res.push_back(node->val);
    if(node->right)
        Dfs(node->right);
    return;
}
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        Dfs(root);
        return res;
    }
};
