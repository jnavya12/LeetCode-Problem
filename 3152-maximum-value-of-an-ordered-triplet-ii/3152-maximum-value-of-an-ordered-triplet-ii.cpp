class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxTripletValue = 0;

        vector<int> maxLeft(n, 0);
        maxLeft[0] = nums[0];

        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }

        vector<int> maxRight(n, 0);
        maxRight[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], nums[i]);
        }

        for (int j = 1; j < n - 1; j++) {
            long long leftMax = maxLeft[j - 1];
            long long rightMax = maxRight[j + 1];

            long long tripletValue = (leftMax - nums[j]) * rightMax;
            maxTripletValue = max(maxTripletValue, tripletValue);
        }

        return maxTripletValue;
    }
};
