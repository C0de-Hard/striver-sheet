class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        k = n-k;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[(i+k)%n];
        }
        for (int i = 0; i < n; i++) nums[i] = ans[i];
    }
};