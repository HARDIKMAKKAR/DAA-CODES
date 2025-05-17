#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 100;
int parent[MAX];  
struct Edge {
    int u, v, weight;
};
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) parent[rootV] = rootU;
}
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}
int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    Edge edges[100]; 
    for (int i = 1; i <= n; i++) parent[i] = i;
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    sort(edges, edges + m, compare);
    int minCost = 0;
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;
        if (find(u) != find(v)) {  // If u and v are in different components
            unionSet(u, v);  // Join the components
            minCost += w;    // Add the weight to the total cost
            cout << u << " - " << v << " : " << w << endl;
        }
    }
    cout << "\nMinimum Cost of Spanning Tree: " << minCost << endl;
}