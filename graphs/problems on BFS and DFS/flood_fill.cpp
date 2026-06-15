#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int curr, int tgt_color) {
        image[i][j] = tgt_color; // Change current cell to target color

        int m = image.size(), n = image[0].size();
        vector<pair<int,int>> dirs = { {0,-1},{0,1},{-1,0},{1,0} };
        for (auto &dir : dirs) {
            int x = i+dir.first, y = j+dir.second;
            if (isValid(x,y,m,n) && image[x][y] == curr) {
                dfs(image,x,y,curr,tgt_color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image; // Already target color, no fill needed
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};

/*
Notes: FLOOD FILL
What I did wrong:
- None (logic was correct).

Fixes applied:
- None

Improvements suggested by Copilot:
 
Tips:
- Early termination optimization: checking if original color == target color prevents unnecessary DFS.
- Stack overflow risk on huge grids → consider BFS (iterative) as alternative.
- Your dirs vector approach is scalable for 8-directional or custom neighbors.
*/
