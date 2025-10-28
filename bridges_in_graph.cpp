#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
int timer=1;

private:

void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,vector<int>&tin,
vector<int>&low,vector<vector<int>>&bridges){
    vis[node]=1;
    low[node]=tin[node]=timer;
    timer++;

    for(auto it:adj[node]){
        if(it==parent) continue;

        if(vis[it]==0){
        dfs(it,node,vis,adj,tin,low,bridges);
        low[node]=min(low[node],low[it]);

        //check for bridge
        if(low[it]>tin[node]){
            bridges.push_back({node,it});
        }
        }
        else{
        low[node]=min(low[node],low[it]);
        }
    }

}

public:
vector<vector<int>>criticalConnection(int n,vector<vector<int>>connection){
    vector<vector<int>>adj(n);
    for(auto it:connection){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int>vis(n,0);
    vector<int>tin(n);  //store the time of insertion during insertion
    vector<int>low(n);  //minimum of all adjacent node apart from parent
    vector<vector<int>>bridges;
    dfs(0,-1,vis,adj,tin,low,bridges);
    return bridges;
}
};

int main() {
    Solution s;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> res = s.criticalConnection(4, connections);

    for (auto &v : res) {
        cout << v[0] << " " << v[1] << endl;
    }
}
