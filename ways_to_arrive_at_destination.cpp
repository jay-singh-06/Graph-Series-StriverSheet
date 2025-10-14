#include<bits/stdc++.h>
using namespace std;

//tc= dijskstra with a min heap=0(E log V)
// adj (adjacency list): O(V + E)
// dist + ways: O(V)
// priority queue: up to O(V)
// So overall:s.c=0(E+v)

int countPaths(int n,vector<vector<int>>&roads){
    vector<vector<pair<int,int>>>adj(n);

    for(auto it:roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    // {dis,node}
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    vector<long long>dist(n,1e18),ways(n,0);//prevention for overflow
    dist[0]=0;
    ways[0]=1;
    pq.push({0,0});
    long long mod=1e9+7;//leetcode ask to convert ask in mod 10^9+7

    while(!pq.empty()){
    long long d=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it:adj[node]){
        int adjNode=it.first;
        int edWt=it.second;

        if(d+edWt<dist[adjNode]){
            dist[adjNode]=d+edWt;
            pq.push({d+edWt,adjNode});
            ways[adjNode]=ways[node];
        }
        else if(d+edWt==dist[adjNode]){
         ways[adjNode]=(ways[adjNode]+ways[node])%mod;
        }
    }
    }
    return ways[n-1]%mod;
}

int main() {
    // Example 1
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
        {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}
    };

    cout << "Number of ways to reach node " << n-1 << " = " 
         << countPaths(n, roads) << endl;

    // Example 2 (your stress test: long chain)
    int m = 200;
    vector<vector<int>> chain;
    for (int i = 0; i < m-1; i++) {
        chain.push_back({i, i+1, 1000000000});
    }

    cout << "Number of ways to reach node " << m-1 << " = " 
         << countPaths(m, chain) << endl;

    return 0;
}