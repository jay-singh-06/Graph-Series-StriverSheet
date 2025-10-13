#include<bits/stdc++.h>
using namespace std;
//t.c=it is directed graph so no of edges=0(size of flights) and it will processed through k
//t.c=0(e*k),s.c=0(n) for dist+0(n*k)for queue+(n+e)=0(n*k+e)

int findCheapestPrice(int n,vector<vector<int>>flights,int src,int dest,int k){
vector<vector<pair<int,int>>>adj(n);
for(auto it:flights){
    adj[it[0]].push_back({it[1],it[2]});
}

//{stops,{node,}}
queue<pair<int,pair<int,int>>>q;
q.push({0,{src,0}});

vector<int>dist(n,1e9);
dist[src]=0;

while(!q.empty()){
    auto it=q.front();
    q.pop();
    int stops=it.first;
    int node=it.second.first;
    int cost=it.second.second;

    if(stops>k) continue;

    for(auto iter:adj[node]){
        int adjNode=iter.first;
        int edWt=iter.second;

        if(cost+edWt<dist[adjNode] && stops<=k){
        dist[adjNode]=cost+edWt;
        q.push({stops+1,{adjNode,cost+edWt}});
        }
    }
}
if(dist[dest]==1e9) return -1;
return dist[dest];
}

int main() {
    int n = 4; // number of cities
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int src = 0;
    int dest = 3;
    int k = 1;

    int cheapest = findCheapestPrice(n, flights, src, dest, k);
    cout << "Cheapest price: " << cheapest << endl;

    return 0;
}