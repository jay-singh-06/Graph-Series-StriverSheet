#include<bits/stdc++.h>
using namespace std;

//t.c=0(v+2e)+0(logn) for sorting,s.c=0(v)

vector<int> eventualSafeNodes(vector<vector<int>>& adj) {

//eventual safe node means whose adj nodes will  end on terminate node(last)

    int v=adj.size();
    //step 1-first reverse the graph and then apply topo sort then sort it in ascending order
    vector<vector<int>>adjRev(v);
    //step 2- make a indegree vector and initialise at 0
    vector<int>indegree(v,0);
    //step 3- iterating through adjacent node and incrementing by 1 

    for(int i=0;i<v;i++){
     //i->it
     //it->i after reversing the adj 

     for(auto it:adj[i]){
        adjRev[it].push_back(i);
        indegree[i]++;
     }
    }
    //step 4-any node whose indegree is 0 put them first in queue

    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }

    //step 5-whose indegree is greater than 0 go to its adjacent and reduce 
    //indegree if indegree become 0 then push it to queue
    vector<int>safeNodes;
    while(!q.empty()){
        int node=q.front();
        q.pop();
       safeNodes.push_back(node);
       for(auto it:adjRev[node]){
        indegree[it]--;
        if(indegree[it]==0) q.push(it);
       }
    }
    //step 6-sort the safeNode vector in ascending order
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
    }


    int main() {
    int v, e;
    cout << "Enter number of nodes and edges: ";
    cin >> v >> e;

    vector<vector<int>> adj(v);
    cout << "Enter edges (u v) meaning u -> v:\n";
    for (int i = 0; i < e; i++) {
        int u, vtx;
        cin >> u >> vtx;
        adj[u].push_back(vtx);
    }

    vector<int> safe = eventualSafeNodes(adj);

    cout << "Eventual Safe Nodes: ";
    for (int node : safe) cout << node << " ";
    cout << endl;

    return 0;
}