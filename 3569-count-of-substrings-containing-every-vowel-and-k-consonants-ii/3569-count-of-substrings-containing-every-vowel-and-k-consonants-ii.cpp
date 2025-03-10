#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    long countOfSubstrings(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0, end = 0, consonantCount = 0;
        unordered_map<char, int> vowelCount;
        vector<int> nextConsonant(word.size());
        int nextConsonantIndex = word.size();
        
        for (int i = word.size() - 1; i >= 0; i--) {
            nextConsonant[i] = nextConsonantIndex;
            if (!isVowel(word[i])) nextConsonantIndex = i;
        }
        
        while (end < word.size()) {
            isVowel(word[end]) ? vowelCount[word[end]]++ : consonantCount++;
            
            while (consonantCount > k) {
                if (isVowel(word[start])) {
                    if (--vowelCount[word[start]] == 0) vowelCount.erase(word[start]);
                } else consonantCount--;
                start++;
            }
            
            while (start < word.size() && vowelCount.size() == 5 && consonantCount == k) {
                numValidSubstrings += nextConsonant[end] - end;
                if (isVowel(word[start])) {
                    if (--vowelCount[word[start]] == 0) vowelCount.erase(word[start]);
                } else consonantCount--;
                start++;
            }
            end++;
        }
        return numValidSubstrings;
    }
};
