class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        for (int num : nums) {
            if (num < k) return -1;
        }

        set<int, greater<int>> greaterVals;
        for (int num : nums) {
            if (num > k)
                greaterVals.insert(num);
        }

        int operations = 0;
        multiset<int> numSet(nums.begin(), nums.end());

        while (!greaterVals.empty()) {
            int current = *greaterVals.begin();
            greaterVals.erase(greaterVals.begin());

            int h = k;
            if (!greaterVals.empty())
                h = *greaterVals.begin();

            auto it = numSet.upper_bound(h);
            int count = 0;
            int val = -1;
            bool valid = true;
            for (; it != numSet.end(); ++it) {
                if (val == -1) val = *it;
                if (*it != val) {
                    valid = false;
                    break;
                }
                count++;
            }

            if (!valid) return -1;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > h)
                    nums[i] = h;
            }
            numSet = multiset<int>(nums.begin(), nums.end());

            operations++;
        }

        return operations;
    }
};
