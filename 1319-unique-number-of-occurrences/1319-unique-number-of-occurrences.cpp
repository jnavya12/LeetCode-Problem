class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        std::unordered_set<int> occurrences;
        for (const auto& pair : freq) {
            if (!occurrences.insert(pair.second).second) {
                return false;
            }
        }
        return true;
    }
};