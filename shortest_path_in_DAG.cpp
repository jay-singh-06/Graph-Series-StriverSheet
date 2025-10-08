#include<bits/stdc++.h>
using namespace std;

class solution{
private:
//t.c=0(n+m),s.c=0(n+m)
    void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st){
        vis[node]=1;

        for(auto it:adj[node]){
            int v=it.first;
            if(!vis[v]){
              dfs(v,adj,vis,st);
            }
        }
        st.push(node);
    }

    public:

vector<int>shortestPath(int n,int m,vector<vector<int>>edges){
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];

        adj[u].push_back({v,wt});//directed graph
    }

    //step1 = find topo sort
    //plain dfs t.c=0(n+e) edges=m,s.c=0(n) for recursion+0(n)vis+0(n) for stack=0(n)
    vector<int>vis(n,0);
    stack<int>st; //we take stack bcoz we want last in element first of topo bcoz it has dis=0
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    //step 2 do the distance thing t.c=0(n+m)
    //we will put front of stack bcoz it distance is 0 so going from there increases +1 to its adjacent
    vector<int>dist(n,INT_MAX);
    dist[0]=0;
    //t.c=0(n+m) m is edges (adjacent iterator will move m times),s.c=0(n+m) n for adjacency space and m for edges
    while(!st.empty()){
        int node=st.top();
        st.pop();

    for(auto it:adj[node]){
        int v=it.first;
        int wt=it.second;

        if(dist[node]!=INT_MAX && dist[node]+wt<dist[v]){ //if sum of current nodes dist and weight is samller than previous
            //distance which we stored in dist vector so update it
            dist[v]=dist[node]+wt;
        }
    }
    }

// Replace unreachable with -1
        for (int &d : dist) {
            if (d == INT_MAX) d = -1;
        }
        return dist;
    }
};