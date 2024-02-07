#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<pair<int, int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V+1, 0);
    pq.push({0, 1});
    int sum = 0;
    while (!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1){
            continue;
        }
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            if (!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}
int main(){
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V+1];
    for (int i = 1; i <= E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << spanningTree(V, adj) << endl;
    return 0;
}
