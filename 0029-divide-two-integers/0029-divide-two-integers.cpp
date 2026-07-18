class Solution {
public:
    int divide(long long n, long long dvr) {
        bool sign = false;
        if ((n < 0 || dvr < 0) && (n >= 0 || dvr >= 0)) sign = true; 
        n = (n < 0) ? -n : n;
        dvr = (dvr < 0) ? -dvr : dvr;

        long long int q = 0;
        while (n >= dvr) {
            long long int tmp = 0;
            while (n >= (dvr << tmp)) {
                tmp++;
            }
            q += (long long)1 << (tmp-1);
            n -= dvr << (tmp-1);
        }
        //now manage sign
        if (sign) {
            if (-q <= INT_MIN) return INT_MIN;
            return -q;
        }
        else {
            if (q >= INT_MAX) return INT_MAX;
            return q;
        }
        
    }
    int divide(int dividend, int divisor) {
        // if (dividend < divisor) return 0;
        // else if (dividend == divisor) return 1;  
        return divide((long long)dividend,(long long)divisor);
    }
};