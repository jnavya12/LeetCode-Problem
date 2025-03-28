class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> answer(queries.size()), dirs = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < queries.size(); ++i) sorted_queries.emplace_back(queries[i], i);
        sort(sorted_queries.begin(), sorted_queries.end());
        pq.emplace(grid[0][0], 0);
        visited[0][0] = true;
        int count = 0;
        for (auto& [q, idx] : sorted_queries) {
            while (!pq.empty() && pq.top().first < q) {
                auto [val, pos] = pq.top(); pq.pop();
                int r = pos / n, c = pos % n;
                ++count;
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dirs[d], nc = c + dirs[d + 1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        pq.emplace(grid[nr][nc], nr * n + nc);
                    }
                }
            }
            answer[idx] = count;
        }
        return answer;
    }
};
