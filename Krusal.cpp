class Solution {
  public:
  
    void addEdge(vector<list<pair<int,int>>>& graph, int src, int des, int wt) {
        graph[src].push_back({des, wt});    
        graph[des].push_back({src, wt});    
    }
    
    void removeEdge(vector<list<pair<int,int>>>& graph, int src, int des, int wt) {
        graph[src].remove({des, wt});
        graph[des].remove({src, wt});
    }

    
   bool checkCycle(vector<list<pair<int,int>>>& graph, int start) {
        vector<bool> visited(graph.size(), false);
        queue<pair<int,int>> q;  // {node, parent}
        visited[start] = true;
        q.push({start, -1});

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto &neigh : graph[node]) {
                int adjNode = neigh.first;
                if(!visited[adjNode]) {
                    visited[adjNode] = true;
                    q.push({adjNode, node});
                } else if(adjNode != parent) {
                    // visited and not parent => cycle found
                    return true;
                }
            }
        }
        return false;
    }
    
    bool detectCycleByAddingEdge(vector<list<pair<int,int>>>& newTree, int src, int des, int wt) {
    addEdge(newTree, src, des, wt);

    // Check cycle starting from src or des only
    if (checkCycle(newTree, src) || checkCycle(newTree, des)) {
        removeEdge(newTree, src, des, wt);
        return true;
    }
    return false;
}

    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        for (int u = 0; u < V; u++) {
            for (auto &edge : adj[u]) {
                int v = edge[0]; // neighbor
                int w = edge[1]; // weight
                if (u < v) {
                    pq.push({w, {u, v}});
                }
            }
        }
        
        vector<list<pair<int,int>>> newTree(V);
        
        int edgesUsed = 0;
        int cost = 0;
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            int w = x.first;
            int u = x.second.first;
            int v = x.second.second;
            
            if(!detectCycleByAddingEdge(newTree, u, v, w)){
                cost += w;
                edgesUsed++;
            }
        }
        
        if (edgesUsed != V - 1) return -1;
        return cost;
    }
};