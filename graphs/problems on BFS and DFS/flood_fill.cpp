#include <vector>
using namespace std;
class Solution {
public:
    bool isvalid(int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int curr, int tgt_color) {
        image[i][j] = tgt_color;//main

        int m = image.size(), n = image[0].size();
        vector<pair<int,int>> dirs = { {0,-1},{0,1},{-1,0},{1,0} };
        for (auto &dir : dirs) {
            int x = i+dir.first, y = j+dir.second;
            if (isvalid(x,y,m,n) && image[x][y] == curr) {
                dfs(image,x,y,curr,tgt_color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color);//just return(and here skip the dfs)
        else dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};

// its the same algo i studied in CGM
// like boundary fill was used to color inside of a closed area with a color,
// no matter what are the initial color of each pixels
// and in floodfill, it replaces a connected region of a specific target color(which we have to change) with a new fill color
// so if the area is not enclosed and the interior and exterior colors are same(as the target color) then it can run infinitely.
