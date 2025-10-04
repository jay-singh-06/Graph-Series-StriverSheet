#include<bits/stdc++.h>
using namespace std;


//t.c=0(v+e) for directed graph,s.c=0(v)
//You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return true if you can finish all courses. Otherwise, return false.

bool canFinish(int v,vector<vector<int>>&prerequisites){
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
    if(topo.size()==v) return true;
    return false;
}

int main() {
    int v = 4; // number of courses
    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2}};
    // meaning: 0->1->2->3 (no cycle)

    if(canFinish(v, prerequisites)) {
        cout << "Yes, you can finish all courses ✅" << endl;
    } else {
        cout << "No, cycle detected ❌ can't finish all courses" << endl;
    }

    return 0;
}