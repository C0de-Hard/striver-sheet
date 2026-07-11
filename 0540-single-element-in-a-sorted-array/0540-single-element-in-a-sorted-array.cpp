class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorr = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            xorr = nums[i]^xorr;
        }
        return xorr;
    }
};