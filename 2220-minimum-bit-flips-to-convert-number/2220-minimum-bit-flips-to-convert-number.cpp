class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_val = start xor goal;
        return __builtin_popcount(xor_val);

    }
};