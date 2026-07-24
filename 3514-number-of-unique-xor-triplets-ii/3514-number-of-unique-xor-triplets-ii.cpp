class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> tmp_set;
        unordered_set<int> nums_set(nums.begin(),nums.end());
        for (auto &x : nums_set) {
            for (auto &y : nums_set) {
                tmp_set.insert(x^y);
            }
        }

        unordered_set<int> ans_set;
        for (auto &val : tmp_set) {
            for (auto &z : nums_set) {
                ans_set.insert(val^z);
            }
        }
        return ans_set.size();

    }
};