#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0, ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();
            if (time > dist[node]) continue;

            for (auto& [neighbor, travel_time] : graph[node]) {
                long long new_time = time + travel_time;
                if (new_time < dist[neighbor]) {
                    dist[neighbor] = new_time;
                    ways[neighbor] = ways[node];
                    pq.push({new_time, neighbor});
                } else if (new_time == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
