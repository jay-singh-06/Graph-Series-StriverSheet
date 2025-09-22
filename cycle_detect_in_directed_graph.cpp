#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>&adj){
  vis[node]=1;
  pathVis[node]=1;

  //traverse for adjacent node
  for(auto it:adj[node]){
    //when the node  is not visited
    if(!vis[it]){
        if(dfsCheck(it,vis,pathVis,adj)==true) return true;
    }
    //if visited and comes in same same path then true else false
    else if(pathVis[it]){
        return true;
    }
  }
  pathVis[node]=0;
  return false;
}

bool isCyclic(vector<vector<int>>&adj){
int v=adj.size();

vector<int>vis(v,0);
vector<int>pathVis(v,0);

for(int i=0;i<v;i++){
    if(!vis[i]){
        if(dfsCheck(i,vis,pathVis,adj)==true) return true;
    }
}
return false;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {1}; // cycle: 1 -> 2 -> 3 -> 1

    if (isCyclic(adj)) cout << "Graph has a cycle\n";
    else cout << "Graph has no cycle\n";

    return 0;
}