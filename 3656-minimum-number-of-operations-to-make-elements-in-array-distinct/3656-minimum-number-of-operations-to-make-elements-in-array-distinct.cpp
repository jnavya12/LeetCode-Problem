class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        while (true) {
            unordered_set<int> seen;
            bool isDistinct = true;

            for (int i = operations * 3; i < n; ++i) {
                if (seen.count(nums[i])) {
                    isDistinct = false;
                    break;
                }
                seen.insert(nums[i]);
            }

            if (isDistinct) return operations;

            operations++;

            if (operations * 3 >= n) return operations;
        }
    }
};
