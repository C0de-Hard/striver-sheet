class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int bits = 32-1;
        while (n) {
            int curr = n & 1;
            if (curr != 0) {
                curr = curr << bits;
                ans = ans | curr;
            }
            n = n >> 1;
            bits--;
        }
        return ans;
    }
};