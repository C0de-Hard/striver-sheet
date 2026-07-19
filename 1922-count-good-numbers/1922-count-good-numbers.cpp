class Solution {
    long long mod = 1e9+7;
public:
    long long pow(long long base, long long exp) {
        if (exp == 0) return 1;
        long long ans = pow(base,exp/2)%mod;
        ans = (ans*ans)%mod;
        if (exp%2 == 1) ans = (ans*base)%mod;
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        long long evenAns = pow(5,(n+1)/2);
        long long oddPrimeAns = pow(4,n/2);
        cout << "evenAns = " << evenAns << endl;
        cout << "oddPrimeAns = " << oddPrimeAns << endl;
        return evenAns*oddPrimeAns%mod;
    }
};