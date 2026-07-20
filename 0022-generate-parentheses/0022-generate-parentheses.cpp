class Solution {
    vector<string> ans;
public:
    void fn(string curr, int n, int open = 0, int close = 0) {
        if (curr.length() == 2*n) {
            ans.push_back(curr);
        }
        if (open < n) fn(curr+'(',n,open+1, close);
        if (close < open) fn(curr+')',n,open, close+1);
        
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        fn("",n);
        return ans;
    }
};