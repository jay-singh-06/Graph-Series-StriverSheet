#include<bits/stdc++.h>
using namespace std;

//we have to find mst and also sometime they ask for sum of edges

int spanningTree(int v,vector<vector<pair<int,int>>>adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int>vis(v,0);
    pq.push({0,0});//{wt,node}
    int sum=0;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;

        if(vis[node]==1) continue;
        //else vis[node]=1
        vis[node]=1;
        sum+=wt;

        for(auto it:adj[node]){
            int adjNode=it.first;
            int edWt=it.second;
            if(!vis[adjNode]){
                pq.push({edWt,adjNode});
            }
        }

    }
    return sum;//sum of mst edges
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    // Example edges (undirected graph)
    vector<tuple<int,int,int>> edges = {
        {0,1,2}, {0,3,6}, {1,2,3}, {1,3,8}, {1,4,5}, {2,4,7}, {3,4,9}
    };

    for (auto edge : edges) {
    int u = get<0>(edge);
    int v = get<1>(edge);
    int w = get<2>(edge);

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}


    cout << "Sum of MST edges = " << spanningTree(V, adj) << endl;
}