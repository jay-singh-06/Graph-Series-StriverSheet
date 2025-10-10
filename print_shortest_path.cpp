#include<bits/stdc++.h>
using namespace std;

// this is  Dijkstra's Algorithm

//approach is very normal we use a priority_queue,distance vector and parent vector
//first we put src in pq with distance 0 and so,dis[1]=0 bcoz our indexing is 1 base
//our parent index size will be n+1 and we fill with index  like n=5 12345
//and we fill distane as infinity and look for minium we put top of pq and iterate
//through its adjacent if its dist+edg<our previously stored distance then we update it
//and put in pq and also update its parent with its node index at last, we put our node=n
// and check if parent is updated or not if it is updated then put node then parent and repeat

//summary->Always take the node with the smallest distance so far, relax its neighbors, and update distances if shorter."

//t.c=0(n+m)*logn (because each edge can go into the priority queue, and operations take log n)
//s.c=O(n + m) (adjacency list + dist + parent).

vector<int>shortestPath(int n,int m,vector<vector<int>>&edges){
vector<vector<pair<int,int>>>adj(n+1); //{adjNode,weight}

for(auto it:edges){
    adj[it[0]].push_back({it[1],it[2]});
    adj[it[1]].push_back({it[0],it[2]});  //undirected graph
}


//for max heap we take simple priority_queue<pair<int,int>>pq but we want minimum 
//so we use priority_queue<pair<int,int>,vector<int,int>>,greater<pair<int,int>>>pq for min heap
//so why we use priority queue bcoz edge weight is here not unit it changes sometimes too large sometime too small so we want min heap
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>dist(n+1,INT_MAX);
vector<int>parent(n+1);
for(int i=1;i<=n;i++){
    parent[i]=i; //if n=5 so parent vector will initialise as 1 2 3 4 5 
}
dist[1]=0;
pq.push({0,1}); //priority queue will starts from first node and distance 0
while(!pq.empty()){

    auto it=pq.top();
    int d=it.first;
    int node=it.second;
    pq.pop();

    //iterating the adjacent of node{adjNode,edgeWeight}
    for(auto it:adj[node]){
        int adjNode=it.first;
        int edWt=it.second;
        if(d+edWt<dist[adjNode]){
         dist[adjNode]=d+edWt;
         pq.push({d+edWt,adjNode});
         parent[adjNode]=node;
        }
    }
}
if(dist[n]==INT_MAX) return {-1};
vector<int>path;
int node=n;
//t.c=0(n)
while(parent[node]!=node){
 path.push_back(node);
 node=parent[node]; //this will put parent node after node
}
  path.push_back(1);
  reverse(path.begin(),path.end());
  return path;
}

int main() {
    int n = 5, m = 6;
    // edges: {u, v, w}
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };

    vector<int> path = shortestPath(n, m, edges);

    if (path.size() == 1 && path[0] == -1) {
        cout << "No path exists!\n";
    } else {
        cout << "Shortest path: ";
        for (int node : path) cout << node << " ";
        cout << "\n";
    }
    return 0;
}