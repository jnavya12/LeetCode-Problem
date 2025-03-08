class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, maxCount = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < k; i++) if (vowels.count(s[i])) count++;
        maxCount = count;
        for (int i = k; i < s.size(); i++) {
            count += vowels.count(s[i]) - vowels.count(s[i - k]);
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
