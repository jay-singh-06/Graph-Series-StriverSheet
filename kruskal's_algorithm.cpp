#include<bits/stdc++.h>
using namespace std;

//kruskals algorithm is use to find sum of weight of edges of minimum spanning tree using disjoint set

class disjointSet{
vector<int>rank,parent,size;

public:
//constructor
disjointSet(int n){
    rank.resize(n+1,0); //rank vector size=n initialise with 0
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
}

//function to find ultimate parent
int findUParent(int node){
    if(node==parent[node]) return node; //if a node itself is a parent (starting)
    return parent[node]=findUParent(parent[node]);
}

//size=no of nodes
void  unionBySize(int u,int v){
    int ulp_u=findUParent(u);
    int ulp_v=findUParent(v);
    if(ulp_u==ulp_v) return;
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}
};

class solution{

    public:
    //function to find the weight of edges of the mst
    int spanningTree(int v,vector<vector<pair<int,int>>>&adj){

        vector<pair<int,pair<int,int>>>edges;

        for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            int adjNode=it.first;
            int wt=it.second;
            int node=i;

            edges.push_back({wt,{node,adjNode}});
        }
        }
        disjointSet ds(v);
        sort(edges.begin(),edges.end());
        int mstWt=0;

        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;

            //if both edges are not in same component then sum their edge
            if(ds.findUParent(u)!=ds.findUParent(v)){
                mstWt+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};

int main() {
    int V = 4; // number of vertices
    vector<vector<pair<int,int>>> adj(V);

    // Undirected edges
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({2, 6});
    adj[2].push_back({0, 6});

    adj[0].push_back({3, 5});
    adj[3].push_back({0, 5});

    adj[1].push_back({3, 15});
    adj[3].push_back({1, 15});

    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});

    solution obj;
    cout << "Weight of MST: " << obj.spanningTree(V, adj) << endl;

    return 0;
}