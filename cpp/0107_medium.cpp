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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        function<void()> Bfs = [&]()
        {
            queue<pair<TreeNode *, int>> q;
            q.emplace(root, 0);
            vector<int> layer;

            int level_global = 0;
            while (!q.empty())
            {
                TreeNode *node = q.front().first;
                int level_cur = q.front().second;
                q.pop();
                if (level_cur > level_global)
                {
                    level_global++;
                    res.push_back(layer);
                    layer = vector<int>();
                }
                layer.push_back(node->val);
                if (node->left)
                    q.emplace(node->left, level_cur + 1);
                if (node->right)
                    q.emplace(node->right, level_cur + 1);
            }
            res.push_back(layer);

            return;
        };

        Bfs();
        reverse(res.begin(), res.end());
        return res;
    }
};