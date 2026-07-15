class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();//will be in form 3m + 1
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int count_set_bits = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & (1 << i)) count_set_bits++;
            }
            if (count_set_bits%3 == 0); //do nothing
            else if (count_set_bits%3 == 1) ans = ans | (1 << i);
            
        }
        return ans;
    }
};