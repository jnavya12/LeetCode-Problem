class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = *max_element(candies.begin(), candies.end()), mid, res = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            long long count = 0;
            for (int c : candies) {
                count += c / mid;
            }
            if (count >= k) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
