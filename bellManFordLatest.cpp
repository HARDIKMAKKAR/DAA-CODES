
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);  // Use large value as INF
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; ++i) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycle
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};  // GFG expects -1 if a negative cycle is found
            }
        }

        return dist;
    }
};