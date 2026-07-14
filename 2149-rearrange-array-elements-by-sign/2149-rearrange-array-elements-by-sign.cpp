class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[j] = nums[i];
                j++,j++;
            }
        }
        for (int i = 0, j = 1; i < n; i++) {
            if (nums[i] < 0) {
                ans[j] = nums[i];
                j++,j++;
            }
        }
        return ans;
    }
};