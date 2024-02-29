#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

// 方法超时
bool RECURIT_OVER;
vector<int> route;
vector<bool> if_vis;
vector<vector<int>> adj_matrix;

void Dfs(int &node, int &target)
{
    if_vis[node] = true;
    if (node == target)
    {
        RECURIT_OVER = true;
        return;
    }
    else
    {
        for (int n = 0; n < adj_matrix.size(); n++)
        {
            if (adj_matrix[node][n] && !if_vis[n])
            {
                route.push_back(adj_matrix[node][n]);
                Dfs(n, target);
                route.pop_back();
            }
        }
    }
    if_vis[node] = false;
    return;
}

inline int GetMinOpt(vector<int> &route)
{
    unordered_map<int, int> map_same_length;
    int max_length_num = 0;
    for (int n = 0; n < route.size(); n++)
    {
        max_length_num = max(max_length_num, ++map_same_length[route[n]]);
    }

    return route.size() - max_length_num;
}

class Solution
{
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        if_vis = vector<bool>(n);
        adj_matrix = vector<vector<int>>(n, vector<int>(n, 0));
        vector<int> res;

        for (int i = 0; i < n - 1; i++)
        {
            adj_matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            adj_matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (vector<int> query : queries)
        {
            RECURIT_OVER = false;
            route = vector<int>();
            Dfs(query[0], query[1]);
            res.push_back(GetMinOpt(route));
        }

        return res;
    }
};

const int W = 26;

class Solution_
{
public:
    int find(vector<int> &uf, int i)
    {
        if (uf[i] == i)
        {
            return i;
        }
        uf[i] = find(uf, uf[i]);
        return uf[i];
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        int m = queries.size();
        vector<unordered_map<int, int>> neighbors(n);
        for (auto &edge : edges)
        {
            neighbors[edge[0]][edge[1]] = edge[2];
            neighbors[edge[1]][edge[0]] = edge[2];
        }
        vector<vector<pair<int, int>>> queryArr(n);
        for (int i = 0; i < m; i++)
        {
            queryArr[queries[i][0]].push_back({queries[i][1], i});
            queryArr[queries[i][1]].push_back({queries[i][0], i});
        }

        vector<vector<int>> count(n, vector<int>(W + 1));
        vector<int> visited(n), uf(n), lca(m);
        function<void(int, int)> tarjan = [&](int node, int parent)
        {
            if (parent != -1)
            {
                count[node] = count[parent];
                count[node][neighbors[node][parent]]++;
            }
            uf[node] = node;
            for (auto [child, _] : neighbors[node])
            {
                if (child == parent)
                {
                    continue;
                }
                tarjan(child, node);
                uf[child] = node;
            }
            for (auto [node1, index] : queryArr[node])
            {
                if (node != node1 && !visited[node1])
                {
                    continue;
                }
                lca[index] = find(uf, node1);
            }
            visited[node] = 1;
        };
        tarjan(0, -1);
        vector<int> res(m);
        for (int i = 0; i < m; i++)
        {
            int totalCount = 0, maxCount = 0;
            for (int j = 1; j <= W; j++)
            {
                int t = count[queries[i][0]][j] + count[queries[i][1]][j] - 2 * count[lca[i]][j];
                maxCount = max(maxCount, t);
                totalCount += t;
            }
            res[i] = totalCount - maxCount;
        }
        return res;
    }
};
