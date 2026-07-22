class Solution {
public:
    int countMaxConsecutive(set<int> & sett) {//length will be always even like 0, 2 ...
        if (sett.empty()) return 0;
        int ans = 0;
        for (auto itr = sett.begin(); itr != sett.end(); ) {
            int count = 0;
            for (int tmp = *itr; itr != sett.end(); tmp++,itr++) {
                if (tmp == *itr) count++;
                else break;
            }
            ans = max(count,ans);
            if (itr == sett.end()) break;
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        // set<int> x = {1,2,4,5,3};
        // return countMaxConsecutive(x);
        stack<int> st;
        set<int> ans;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (!st.empty()) {
                ans.insert(st.top());
                ans.insert(i);
                st.pop();

            }
        }
        return countMaxConsecutive(ans);
    }
};