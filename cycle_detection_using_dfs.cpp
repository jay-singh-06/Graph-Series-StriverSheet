#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int parent,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
     if(!vis[it]){
        if(dfs(it,node,vis,adj)==true) return true;
     }
     else if(it!=parent) return true;
    }
    return false;
}

bool isCycle(int v,vector<int>adj[]){
    vector<int> vis(v,0);
    //it has multiple coonecting components
    for(int i=0;i<v;i++){
    if(!vis[i]){
        if(dfs(i,-1,vis,adj)==true)return true;
    }
    }
    return false;
}

int main() {
    int v = 5;
    vector<int> adj[v];

    // Example graph: 0-1-2-3 and 3-4 (no cycle)
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);

    if(isCycle(v, adj)) cout << "Cycle Found\n";
    else cout << "No Cycle\n";

    return 0;
}
