// #include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(const vector<vector<int>>& grid, int curr, vector<bool>& vis) {
        int n = grid.size();
        vis[curr] = true;
        for (int j = 0; j < n; j++) {
            if (grid[curr][j] && !vis[j]) {
                dfs(grid,j,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int ans = 0;
        for (int i = 0; i < n; i++) { //coz max possible ans is n(when all are disconnected)
            if (!vis[i]) {
                dfs(isConnected,i,vis);
                ans++;
            }
        }
        return ans;
    }
};
