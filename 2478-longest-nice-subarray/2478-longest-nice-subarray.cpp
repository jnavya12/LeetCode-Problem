class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int bitmask = 0;
        int max_length = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((bitmask & nums[right]) != 0) {
                bitmask ^= nums[left];
                left++;
            }
            bitmask |= nums[right];
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};
