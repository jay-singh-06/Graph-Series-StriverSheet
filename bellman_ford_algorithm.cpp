#include<bits/stdc++.h>
using namespace std;

//it is second method after djisktra algorithm for finding distance
//it is used when we have negative cycle or negative edge weight it only apply on directed graph
//it graph is undirected then make it directed using two directed graph of same edge weight

vector<int>bellmanFord(int v,vector<vector<int>>&edges,int s){
    vector<int>dis(v,INT_MAX);
    dis[s]=0;
    for(int i=0;i<v-1;i++){
    
        //applying bellman ford algorithm
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        if(dis[u]!=INT_MAX && dis[u]+wt<dis[v]){
            dis[v]=dis[u]+wt;
        }
    }
    }

    //n th relaxation for checking negative cycle
    for(auto it:edges){
        int u=it[0];
        int node=it[1];
        int wt=it[2];

        if(dis[u]!=INT_MAX && dis[u]+wt<dis[node]){
            dis[node]=dis[u]+wt;
            return {-1};
        }
    }
   return dis;
}

int main() {
    int V, E;  
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;  
    cout << "Enter edges (u v wt):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int S;
    cout << "Enter source vertex: ";
    cin >> S;

    vector<int> result = bellmanFord(V, edges, S);

    if (result.size() == 1 && result[0] == -1) {
        cout << "Graph contains a negative weight cycle\n";
    } else {
        cout << "Shortest distances from source " << S << ":\n";
        for (int i = 0; i < V; i++) {
            if (result[i] == INT_MAX) cout << "INF ";
            else cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}