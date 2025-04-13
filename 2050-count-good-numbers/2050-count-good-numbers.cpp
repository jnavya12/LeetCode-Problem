class Solution {
public:
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        return (int)(modPow(5, evenCount, MOD) * modPow(4, oddCount, MOD) % MOD);
    }
    
    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }
};
