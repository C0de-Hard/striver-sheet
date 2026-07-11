class Solution {
public:
    void countLen(vector<vector<int>>& g, int node, vector<bool>& vis, int* ptr) {
        vis[node] = true;
        *ptr = *ptr+1;
        // cout << node << " ";
        for (int nbr : g[node]) {
            if (!vis[nbr]) {
                countLen(g,nbr,vis,ptr);
                
            }
        }
    }
    bool checkComplete(vector<vector<int>>& g, int node, int c) {
        if (g[node].size() != c) return false;
        for (int nbr : g[node]) {
            if (g[nbr].size() != c) return false;
        }
        return true;
    } 
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto p : edges) {
            int u = p[0], v = p[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int c = 0;
                countLen(g,i,vis,&c);
                if (checkComplete(g,i,c-1)) ans++;
            }
        }
        return ans;
    }
};