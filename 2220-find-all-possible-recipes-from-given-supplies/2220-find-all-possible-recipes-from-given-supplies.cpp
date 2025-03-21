class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> result;

        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        for (const string& sup : supplies) {
            q.push(sup);
        }

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (inDegree.count(curr)) {
                result.push_back(curr);
            }

            for (const string& next : graph[curr]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return result;
    }
};
