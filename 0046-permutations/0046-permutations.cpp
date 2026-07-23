class Solution {
    vector<vector<int>> ans;
public:
    void perms(vector<int>& nums, vector<bool>& vis, vector<int>& curr, int i = 0) {
        int n = nums.size();
        if (i == n) {
            ans.push_back(curr);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                vis[j] = true;
                curr[i] = nums[j];
                perms(nums,vis,curr,i+1);
                vis[j] = false;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        int n = nums.size();
        vector<bool> vis(n,false);
        vector<int> curr(n);
        perms(nums,vis,curr);
        return ans;
    }
};