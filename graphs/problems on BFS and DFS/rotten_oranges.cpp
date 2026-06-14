// #include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

// Quick review notes moved below (kept minimal per request).
class Solution {
/*
Notes: ROTTEN ORANGES
What I did wrong:
- None (logic was correct).

Fixes applied:
- None needed.

Improvements suggested by Copilot:
- Instead of full-grid scan with isAnyFreshLeft() at end, count fresh oranges initially and decrement as you rot them. Then check fresh==0.

Tips:
(ask before writing)
*/
public:
    bool inBounds(int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<array<int,3>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j,0});
                }
                else if (grid[i][j] == 1) fresh++;
            }
        }
        int max_lvl = 0;
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            auto [i,j,lvl] = q.front();
            q.pop();

            max_lvl = lvl;//coz last level elements will be popped at last

            for (auto &pair : dirs) {
                int x = i+pair.first, y = j+pair.second;
                if (inBounds(x,y,m,n) && grid[x][y] == 1) {//bottom
                    grid[x][y] = 2;
                    q.push({x,y,lvl+1});
                    fresh--;
                }
            }

        }
        if (fresh == 0) return max_lvl;
        return -1;

        

/*
Notes: ROTTEN ORANGES
What I did wrong:
- None (logic was correct).

Fixes applied:
- None needed.

Improvements suggested by Copilot:
- Instead of full-grid scan with isAnyFreshLeft() at end, count fresh oranges initially and decrement as you rot them. Then check fresh==0.
*/

    }
};