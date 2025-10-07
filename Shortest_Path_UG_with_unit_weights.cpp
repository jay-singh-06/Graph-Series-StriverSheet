#include<bits/stdc++.h>
using namespace std;

//t.c=0(n+2e),s.c=0(v)
vector<int>shortestPath(vector<vector<int>>edges,int n,int m,int src){
    vector<vector<int>>adj(n);
  for(auto it:edges){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]); //undirected graph
  }
  vector<int>dis(n);
  for(int i=0;i<n;i++){
    dis[i]=1e9; //distance vector is initialise as infinite
  }
  dis[src]=0; 
  queue<int>q;
  q.push(src); //initialise queue with first node/src

  while(!q.empty()){
  int node=q.front();
  q.pop();
  for(auto it:adj[node]){   //iterating their adjacent
     //for every vertices we +1 the distance
    if(dis[node]+1<dis[it]){ 
      dis[it]=1+dis[node];
      q.push(it);
    }
  }
  }

  vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
      if(dis[i]!=1e9){  //if we have minimum distance not infintyy then put it in ans else return -1
        ans[i]=dis[i];
      }
    }
    return ans;
  }

  int main() {
    int n = 6, m = 7;
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,3}, {2,4}, {3,5}, {4,5}, {1,2}
    };
    int src = 0;

    vector<int> result = shortestPath(edges, n, m, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << result[i] << "\n";
    }

    return 0;
}