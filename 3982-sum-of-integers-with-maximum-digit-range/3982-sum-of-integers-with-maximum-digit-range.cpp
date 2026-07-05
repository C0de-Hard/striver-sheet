class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = INT_MIN;
        unordered_map<int,vector<int>> mp;
        for (int &num : nums) {
            string str = to_string(num);
            auto [minItr,maxItr] = minmax_element(str.begin(),str.end());
            // cout << "max is " << *maxItr;
            // cout << "min is " << *minItr;
            // cout << "diff is " << *maxItr-*minItr;
            mp[*maxItr-*minItr].push_back(num);
            maxRange = max(maxRange,*maxItr-*minItr);
        }
        for (auto &ptr : mp) {
            if (ptr.first == maxRange){
                int ans = 0;
                for (int &num : ptr.second) {
                    ans += num;
                }
                return ans;
            } 
        }
        return -100;
        
    }
};