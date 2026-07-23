class Solution {
    vector<vector<int>> ans;
public:
    void fn(int i, int size, int sum, vector<int>& curr, int val = 1) {
        // cout << " called " << i << " ";
        if (i == size) {
            if (sum == 0) {
                ans.push_back(curr);
                for (int val : curr) cout << val << " ";
                cout << endl;
            }
            return;
        }
        curr.push_back(0);
        for (int j = val; j <= sum && j <= 9; j++) {
            curr[i] = j;

            fn(i+1,size,sum-j,curr,j+1);
            if (j > sum) {
                break;
            }
        }
        curr.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        fn(0,k,n,curr);
        return ans;
    }
};