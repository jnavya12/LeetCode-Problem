class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> dict;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;

        for (int i = base; i < base * 10; i++) {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long palNum = stoll(s);

            if (palNum % k == 0) {
                sort(s.begin(), s.end());
                dict.insert(s);
            }
        }

        vector<long long> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long long ans = 0;
        for (const string& s : dict) {
            vector<int> count(10);
            for (char c : s) count[c - '0']++;

            long long total = 0;
            for (int first = 1; first <= 9; ++first) {
                if (count[first] == 0) continue;

                count[first]--;
                long long perms = factorial[n - 1];
                for (int c : count) perms /= factorial[c];
                total += perms;
                count[first]++;
            }
            ans += total;
        }

        return ans;
    }
};
