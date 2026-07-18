class Solution {
public:
    double pow(double x, long long n) {
        if (n == 0) return 1;
        double halfPow = myPow(x,n/2);

        double curr = halfPow*halfPow;
        if (n%2) return x*curr;
        return curr;
    }
    double myPow(double x, int n) {
        if (n < 0) return 1/pow(x,(long long)(-1)*(long long)n);
        return pow(x,n);
    }
};