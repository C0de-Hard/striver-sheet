class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;//counter ones for each bit
        int twos = 0;//counter twos for each bit
        for (int x : nums) {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        cout << twos;
        return ones;
    }
};