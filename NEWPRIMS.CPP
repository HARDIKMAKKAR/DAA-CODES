class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min-heap to store {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<bool> visited(V, false);
        int sum = 0;
        
        // Start from node 0 with 0 weight
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto topPair = pq.top();
int wt = topPair.first;
int node = topPair.second;

            pq.pop();
            
            // Skip if already in MST
            if (visited[node]) continue;
            
            visited[node] = true;
            sum += wt; // Add edge weight to MST total
            
            for (auto &neigh : adj[node]) {
                int adjNode = neigh[0];
                int edgeWt = neigh[1];
                
                if (!visited[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        
        return sum; // Total weight of MST
    }
};