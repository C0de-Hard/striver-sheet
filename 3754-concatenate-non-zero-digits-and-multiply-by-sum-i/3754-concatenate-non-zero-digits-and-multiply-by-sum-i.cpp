class Solution {
public:
    long long sumAndMultiply(int n) {
        long int x = 0, sum = 0;
        long long place = 1;
        while (n) {
            int digit = n%10;
            if (digit != 0) {
                x = digit*place+x;
                sum += digit;
                place*=10;
            }
            n = n/10;
        }

        return x*sum;
    }
};