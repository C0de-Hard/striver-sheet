class Solution {
    vector<vector<int>> ans;
public:
    void fn(vector<int>& nums, int n, vector<int> curr_vec = {}) {
        if (n == 0) {
            ans.push_back(curr_vec);
            return;
        }
        fn(nums,n-1,curr_vec);
        curr_vec.push_back(nums[n-1]);
        fn(nums,n-1,curr_vec);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(); 
        fn(nums,n);
        return ans;
    }
};