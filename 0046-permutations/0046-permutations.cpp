class Solution {
    vector<vector<int>> ans;
public:
    void perms(vector<int>& nums, int swap_idx = 0) {
        int n = nums.size();
        if (swap_idx == n) {
            ans.push_back(nums);
            return;
        }
        for (int i = swap_idx; i < n; i++) {
            swap(nums[swap_idx],nums[i]);
            perms(nums,swap_idx+1);
            swap(nums[swap_idx],nums[i]);
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        int n = nums.size();
        perms(nums);
        return ans;
    }
};