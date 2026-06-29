class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();
        unordered_set<string> substrs;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                substrs.insert(word.substr(i,j-i+1));
            }
        }
        int ans = 0;
        for (string &str : patterns) if (substrs.contains(str)) ans++;
        return ans;
    }
};