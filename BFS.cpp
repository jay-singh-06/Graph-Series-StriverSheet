#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E) → We visit each vertex and edge once.
// Space Complexity: O(V) → For vis[], bfs, and queue.

vector<int>bfsOfGraph(int v,vector<int>adj[]){
    vector<int>vis(v,0);
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
     int node=q.front();
     q.pop();
     bfs.push_back(node);

     for(auto it: adj[node]){
        if(!vis[it]){
            vis[it]=1;
            q.push(it);
        }
     }
    }
    return bfs;
}

int main() {
    int v = 5, e = 4;
    vector<int> adj[v];

    // Example graph edges
    vector<pair<int, int>> edges = {{0,1},{0,2},{1,3},{3,4}};
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first); // For undirected graph
    }

    vector<int> ans = bfsOfGraph(v, adj);

    cout << "BFS Traversal: ";
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
