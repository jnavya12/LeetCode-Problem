class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, long long time, int cars) {
        long long totalCars = 0;
        for (int rank : ranks) {
            totalCars += sqrt(time / rank); 
            if (totalCars >= cars) return true;
        }
        return totalCars >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = (long long) *min_element(ranks.begin(), ranks.end()) * (long long) cars * cars;
        long long result = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, mid, cars)) {
                result = mid; 
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }        
        return result;
    }
};
