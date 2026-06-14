#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:

    vector<vector<int>> make_graph(vector<vector<int>>& edges, int n) {
        int m = edges.size();
        vector<vector<int>> g(n);
        for (auto &pair : edges) {
            int u = pair[0], v = pair[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return g;
    }
    bool hasCycleBFS(vector<vector<int>>& g, int node,vector<int>& vis) {
        int n = g.size();

        vis[node] = true;
        queue<pair<int,int>> q;
        q.push({node,-1});//child and parent
        
        while (!q.empty()) {
            auto [ch,p] = q.front();
            q.pop();
            for (int nbr : g[ch]) {
                if (nbr != p) {
                    if (vis[nbr]) {
                        return true;
                    }
                    else {
                        vis[nbr] = true;
                        q.push({nbr,ch});//bcoz the nbr of ch is treated as childs of ch
                    }
                }
            }
            
        }
        return false;
    }  

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g = make_graph(edges,V);
        vector<int> vis(V,false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (hasCycleBFS(g,i,vis)) //for multiple disconnected components
                return true;
            }
        }
        return false;
    }
};