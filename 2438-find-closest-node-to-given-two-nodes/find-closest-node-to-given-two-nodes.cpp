class Solution {
public:
    int n;

    void dfs(int node, vector<int>& edges, vector<int>& visited,
             int dist, vector<int>& distance) {

        visited[node] = true;
        distance[node] = dist;

        int v = edges[node];

        if (v != -1 && !visited[v]) {
            dfs(v, edges, visited, dist + 1, distance);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();

        vector<int> distance(n, INT_MAX);
        vector<int> distance2(n, INT_MAX);

        vector<int> visited(n, false);
        vector<int> visited2(n, false);

        dfs(node1, edges, visited, 0, distance);
        dfs(node2, edges, visited2, 0, distance2);

        int mindist = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int maxi = max(distance[i], distance2[i]);

            if (maxi < mindist) {
                mindist = maxi;
                ans = i;
            }
        }

        return ans;
    }
};