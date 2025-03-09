class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), count = 0;
        std::map<std::vector<int>, int> rowCount;
        for (const auto& row : grid) {
            rowCount[row]++;
        }
        for (int j = 0; j < n; j++) {
            std::vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            count += rowCount[col];
        }
        return count;
    }
};
