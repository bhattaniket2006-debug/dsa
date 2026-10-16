
class Solution {
public:
    int ans = 0;

    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (auto x : adj[node]) {
            int first = x.first;
            int second = x.second;

            if (!visited[first]) {
                if (second == 1) ans++;
                dfs(first, adj, visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<bool> visited(n, false);
        ans = 0;
        dfs(0, adj, visited);

        return ans;
    }
};
