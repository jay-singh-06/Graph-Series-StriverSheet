#include<bits/stdc++.h>
using namespace std;

//t.c=0(v+e),s.c=0(v)
//using kahn's algorithm(bfs)
//we will apply topological sorting and we know if it is acyclic then it will return v size node 
//if it returns smaller than v then it is cyclic

bool isCyclic(int v,vector<vector<int>>&adj){
    //step 1- make a indegree vector and initialise at 0
     vector<int>indegree(v,0);

     //step 2- iterating through adjacent node and incrementing by 1 
     for(int i=0;i<v;i++){
        for(auto it:adj[i]){
         indegree[it]++;
        }
     }

     //step 3-any node whose indegree is 0 put them first in queue
     queue<int>q;
     for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
     }

     //step 4-whose indegree is greater than 0 go to its adjacent and reduce 
    //indegree if indegree become 0 then push it to queue

     vector<int>topo;
     while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);

        for(auto it:adj[node]){
          indegree[it]--;
          if(indegree[it]==0) q.push(it);
        }

     }
     if(topo.size()==v) return false; //no cycle
     return true;
    }

    int main() {
    int v = 4;
    vector<vector<int>> adj(v);

    // Example 1: No cycle (DAG)
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);

    cout << (isCyclic(v, adj) ? "Graph has a cycle\n" : "Graph has no cycle\n");

    // Example 2: Cycle exists
    vector<vector<int>> adj2(v);
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(0); // cycle 0->1->2->0

    cout << (isCyclic(v, adj2) ? "Graph has a cycle\n" : "Graph has no cycle\n");

    return 0;
}