#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    bool inBound(int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<vector<int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                    vis[i][j] = true;
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int level = q.front()[2];
            q.pop();

            for (auto dir : dirs) {
                int x = i + dir.first;
                int y = j + dir.second;
                if (inBound(x, y, m, n)) {
                    if (!vis[x][y]) {
                        mat[x][y] = level + 1;
                        vis[x][y] = true;
                        q.push({x, y, level + 1});
                    }
                }
            }
        }
        return mat;
    }
};

/*
Notes: 01 MATRIX
What I did wrong:
- Initially I tried to run BFS separately from each 1-cell to find the nearest 0.
- I also did not use a visited array to track already processed cells or store computed distances.

Fixes applied:
- Started BFS from all 0-cells at once with level = 0.
- Marked all 0-cells visited before the BFS loop.
- Expanded only to adjacent unvisited cells, which are the 1-cells that still need a distance.
- Reused the given matrix itself to store the distance to the nearest 0, so no extra distance matrix was needed.

Reason BFS works here:
- I knew from the start that BFS is best for nearest-distance problems because it expands in layers.
- Seeding all 0-cells together makes the first time a 1-cell is reached its shortest distance from any 0.
*/