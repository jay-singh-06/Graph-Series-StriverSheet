#include<bits/stdc++.h>
using namespace std;

//undirecteed graph

//t.c=0(n*2e)+0(n),s.c=0(n)+0(n)
bool detect(int src,vector<int>adj[],int vis[]){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto adjacentNode:adj[node]){
            if(!vis[adjacentNode]){
              vis[adjacentNode]=1;
              q.push({adjacentNode,node});
            }
            else if(parent!=adjacentNode){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v,vector<int>adj[]){
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)) return true;
        }
    }
    return false;
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<int> adj[v];

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v2;
        cin >> u >> v2;
        adj[u].push_back(v2);
        adj[v2].push_back(u); // Undirected graph
    }

    if (isCycle(v, adj))
        cout << "Cycle Detected ✅\n";
    else
        cout << "No Cycle ❌\n";

    return 0;
}
