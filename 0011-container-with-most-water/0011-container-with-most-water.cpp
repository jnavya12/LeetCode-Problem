class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, maxWater = 0;
        while (i < j) {
            maxWater = max(maxWater, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;
        }
        return maxWater;
    }
};
