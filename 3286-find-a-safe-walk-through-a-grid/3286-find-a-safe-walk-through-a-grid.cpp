class Solution {
    vector<vector<pair<int,int>>> t;
public:
    bool valid(int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        return true;
    }
    bool findSafeWalkDFS(vector<vector<int>>& grid, int health, int i, int j, vector<vector<bool>>& vis) {
        if (t[i][j] != make_pair(-1,-1)) {
            if (health <= t[i][j].first && t[i][j].second == false) return false;
            else if (health >= t[i][j].first && t[i][j].second == true) return true;//although this never be used
        } 

        if (health == 0) {cout << endl; t[i][j].first = health; return t[i][j].second = false;}
        vis[i][j] = true;
        cout << "(" << i << "," << j << ")";
        int m = grid.size(), n = grid[0].size();
        if (i == m-1 && j == n-1) {
            t[i][j].first = health;
            return t[i][j].second = true;
        }

        vis[i][j] = true;
        vector<pair<int,int>> dirs = {{1,0},{0,1},{0,-1},{-1,0}};
        for (auto &dir : dirs) {
            int x = i + dir.first;
            int y = j + dir.second;
            if (valid(x,y,m,n) && !vis[x][y]) {
                if (grid[x][y] == 1){
                    if (findSafeWalkDFS(grid,health-1,x,y,vis)) {
                        t[i][j].first = health;
                        return t[i][j].second = true;
                    }
                    // else {cout << endl; return false;}
                }
                else {
                    if (findSafeWalkDFS(grid,health,x,y,vis)) {
                        t[i][j].first = health;
                        return t[i][j].second = true;
                    }
                }
            }
        } 
        vis[i][j] = false;
        cout << endl;
        t[i][j].first = health; 
        return t[i][j].second = false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        t = vector<vector<pair<int,int>>>(m,vector<pair<int,int>>(n,{-1,-1}));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        if (grid[0][0]) health--; 
        return (findSafeWalkDFS(grid,health,0,0,vis));
    }
};