#include<bits/stdc++.h>
using namespace std;


//t.c=0(n)+0(2e) for undirected 0(n)+0(e) for directed graph
//s.c=0(n) for vis+0(n) for recursion
void dfs(int node,vector<vector<int>>&adjLs,vector<int>&vis){
    vis[node]=1;
    for(auto it:adjLs[node]){
        if(!vis[it]){
            dfs(it,adjLs,vis);
        }
    }
}

int numProvinces(vector<vector<int>>adj){
    int v=adj.size();
    vector<vector<int>>adjLs(v);
    //changing adj matrix to adj list
    for(int i=0;i<v;i++){
        for(int j=i+1;j<v;j++){
        if(adj[i][j]==1){
         adjLs[i].push_back(j);
         adjLs[j].push_back(i);
        }
    }
    }
    vector<int>vis(v,0);
    int cnt=0;
    for(int i=0;i<v;i++){
    if(!vis[i]){
     cnt++;
     dfs(i,adjLs,vis);
    }
    }
    return cnt;
}

int main() {
    // Example input: 3 provinces
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of Provinces: " << numProvinces(adj) << endl;
    return 0;
}
