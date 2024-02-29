#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        function<void()> Bfs = [&]()
        {
            queue<pair<Node *, int>> q;
            q.emplace(root, 0);
            vector<int> layer;

            int level_global = 0;
            while (!q.empty())
            {
                Node *node = q.front().first;
                int level_cur = q.front().second;
                q.pop();
                if (level_cur > level_global)
                {
                    level_global++;
                    res.push_back(layer);
                    layer = vector<int>();
                }
                layer.push_back(node->val);
                for (Node *child : node->children)
                {
                    q.emplace(child, level_cur + 1);
                }
                // if (node->left)
                //     q.emplace(node->left, level_cur + 1);
                // if (node->right)
                //     q.emplace(node->right, level_cur + 1);
            }
            res.push_back(layer);

            return;
        };

        Bfs();
        return res;
    }
};