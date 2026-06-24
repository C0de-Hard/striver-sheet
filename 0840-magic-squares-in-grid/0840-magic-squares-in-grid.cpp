class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int x, int y) {
        set<int> all_sum;
        all_sum.insert(15);
        for (int i = x; i < x+3; i++) {
            int sum = 0;
            for (int j = y; j < y+3; j++) {
                sum += grid[i][j];
            }
            all_sum.insert(sum);
            if (all_sum.size() > 1) return false;
        }
        for (int j = y; j < y+3; j++) {
            int sum = 0;
            for (int i = x; i < x+3; i++) {
                sum += grid[i][j];
            }
            all_sum.insert(sum);
            if (all_sum.size() > 1) return false;
        }
        int i = x, j = y;
        int sum = 0;
        while (i != x+3) {
            sum += grid[i][j];
            i++,j++;
        }
        if (sum != *all_sum.begin()) return false;
        i = x+2, j = y;
        sum = 0;
        while (i >= x) {
            sum += grid[i][j];
            i--,j++;
        }
        if (sum != *all_sum.begin()) return false;

        return true;
    }
    bool areAllDistinct(vector<vector<int>>& grid, int x, int y) {
        set<int> nums;
        for (int i = x; i < x+3; i++) {
            for (int j = y; j < y+3; j++) {
                if (grid[i][j] >= 10 || grid[i][j] == 0) return false;
                nums.insert(grid[i][j]);
            }
        }
        return nums.size() == 9;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m-2; i++) {
            for (int j = 0; j < n-2; j++) {
                if (areAllDistinct(grid,i,j)) ans += isMagic(grid,i,j);
            }
        }
        return ans;
    }
};