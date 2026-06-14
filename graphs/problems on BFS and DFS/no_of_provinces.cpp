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

    /*
    Notes: NO. OF PROVINCES
    What I did wrong:
    - Made double loops to DFS on each cell but that's wrong. I just needed to check on the unvisited rows (i.e., nodes) and then DFS will handle it (i.e., on cell of that row). This is like the adjacency-list approach.

    Fixes applied:
    - Loop through every node i (0 to n-1). If !vis[i], run DFS from i and increment answer.

    Improvements suggested by Copilot:
    - Passing adjacency matrix as const reference.
    - Removed redundant early vis[i]=true marking.

    Tips:
    - Province count = number of DFS starts from unvisited nodes.
    */
