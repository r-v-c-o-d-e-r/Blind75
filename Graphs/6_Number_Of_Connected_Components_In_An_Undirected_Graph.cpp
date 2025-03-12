#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int ind) {
        visited[ind] = 1;

        for (int u : adj[ind]) {
            if (!visited[u])
                dfs(adj, visited, u);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);

        for (auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};