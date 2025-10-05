#include<bits/stdc++.h>
using namespace std;

//t.c=0(v+e),s.c=0(v)

// You are given an array prerequisites where prerequisites[i] = [ai, bi] 
// indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first
//  take course 1.
// Return the ordering of courses you should take to finish all courses. 
// If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

vector<int> findorder(int v,vector<vector<int>>&prerequisites){
    vector<vector<int>>adj(v);
    for(auto it:prerequisites){
        adj[it[1]].push_back(it[0]);
    }
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

    //step 5-check if it is acyclic 
    if(topo.size()==v) return topo;
    return {};
}

int main() {
    int v = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    // Expected: one valid order is [0,1,2,3] or [0,2,1,3]

    vector<int> order = findorder(v, prerequisites);
    if(order.empty()) {
        cout << "Impossible to finish courses ❌" << endl;
    } else {
        cout << "One possible order: ";
        for(int c : order) cout << c << " ";
        cout << endl;
    }
    return 0;
}