#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <limits.h>
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

vector<vector<int>> ori_list;
void Dfs(TreeNode *node, int row, int column)
{
    if (!node)
        return;
    ori_list.push_back(vector<int>({column, row, node->val}));
    Dfs(node->left, row + 1, column - 1);
    Dfs(node->right, row + 1, column + 1);
    return;
}

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        Dfs(root, 0, 0);
        sort(ori_list.begin(), ori_list.end(), [](vector<int> a, vector<int> b)
             {
            if(a[0]!=b[0])
                return a[0]>b[0];
            else if(a[1]!=b[1])
                return a[1]>b[1];
            return a[2]>b[2]; });

        int cur_row_val = ori_list[0][0];
        vector<int> cur_row;

        for (vector<int> &element : ori_list)
        {
            if (element[0] == cur_row_val)
                cur_row.push_back(element[2]);
            else
            {
                cur_row_val = element[0];
                res.push_back(cur_row);
                cur_row = vector<int>({element[2]});
            }
        }
        res.push_back(cur_row);

        return res;
    }
};

// lambda表达式版本
class Solution_
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<tuple<int, int, int>> nodes;

        function<void(TreeNode *, int, int)> dfs = [&](TreeNode *node, int row, int col)
        {
            if (!node)
            {
                return;
            }
            nodes.emplace_back(col, row, node->val);
            dfs(node->left, row + 1, col - 1);
            dfs(node->right, row + 1, col + 1);
        };

        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int lastcol = INT_MIN;
        for (const auto &[col, row, value] : nodes)
        {
            if (col != lastcol)
            {
                lastcol = col;
                ans.emplace_back();
            }
            ans.back().push_back(value);
        }
        return ans;
    }
};
