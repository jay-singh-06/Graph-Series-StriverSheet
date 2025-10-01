#include<bits/stdc++.h>
using namespace std;

//it is only valid in dag(directed acyclic graph)
//using dfs
//t.c=0(v+2e) v for traversal and 2e for directed graph,s.c=0(2n) n for stack and n for vis

void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}

vector<int>topoSort(int v,vector<vector<int>>&adj){
 vector<int>vis(v,0);
 stack<int>st;
 for(int i=0;i<v;i++){
    if(!vis[i]){
        dfs(i,vis,st,adj);
    }
 }
 vector<int>ans;

  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}

int main() {
    int V = 6;  // Number of vertices
    vector<vector<int>> adj(V);

    // Example DAG edges
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> res = topoSort(V, adj);

    cout << "Topological Sort: ";
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}