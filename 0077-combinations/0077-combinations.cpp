class Solution {
    vector<vector<int>> ans;
public:
    void fn(int i, int size, int num, vector<int>& curr, int val = 1) {
        if (i == size) {
            // if (sum == 0) {
                ans.push_back(curr);
                // for (int val : curr) cout << val << " ";
                // cout << endl;
            // }
            return;
        }
        curr.push_back(0);
        for (int j = val; j <= num; j++) {
            curr[i] = j;

            fn(i+1,size,num,curr,j+1);

        }
        curr.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        fn(0,k,n,curr);//k is size
        return ans;
    }
};