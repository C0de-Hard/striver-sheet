class Solution {
public:
    void fn(int startDig, int n, set<int>& sett) {
        while (startDig + n -1 <= 9) {
            int currDig = startDig;
            int i = 1;
            string s;
            while (i <= n) {
                i++;
                s += to_string(currDig++);
            }
            sett.insert(stoi(s));
            startDig++;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        int n1 = log10(low) + 1;
        int n2 = log10(high) + 1;
        int startDig = low/pow(10,n1-1);
        set<int> sett;
        while (n1 <= n2) {
            fn(startDig,n1,sett);
            startDig = 1;
            n1++;
        }
        vector<int> ans;
        for (int val : sett) {
            if (low <= val && val <= high) ans.push_back(val);
        }
        return ans;

    }
};