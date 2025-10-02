#include<bits/stdc++.h>
using namespace std;

//topological sorting means linear odering of vertices such that if there is an edge between u and v,u->v
//u should be before v in order(output)

//it is only applicable for dag(directed acylic graph) 

//using bfs also known as kahn's algorithm

//steps
//.phele jiska indegree 0 hoga usse queue mai dalo(degree means neighbour,indegree means incoming arrow neigbour)
//.phir sabko ek ek karke queue se nikalo aur uske neigbours ki indegree reduce karte raho jab 0 hojaye usse nikalke uske neighbour ko queue mai daldo and repeat


//t.c=0(v+e) for directed graph,s.c=0(v)

vector<int>topoSort(int v,vector<vector<int>>&adj){
 
    //step 1 make a indegree vector with value 0 and if anybody have adjacent node then iterate to 1 
    vector<int>indegree(v,0);

    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    //step 2 for the node whose indegree is 0 put that in queue first 
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //step 3 whose indegree is greater than 0 go to its adjacent and reduce 
    //indegree if indegree become 0 then push it to queue

    vector<int>topo;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);

        //node is in topo sort
        //so please remove it from indegree

        for(auto it:adj[node]){
         indegree[it]--;
         if(indegree[it]==0)q.push(it);
        }
    }
    
    // step 4check for cycle
     if(topo.size() != v){
        cout << "Cycle detected! Topological sort not possible." << endl;
        return {};
    }

    return topo;

}

int main(){
    int v = 6;
    vector<vector<int>> adj(v);

    // Example edges (DAG)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topoSort(v, adj);

    cout << "Topological Order: ";
    for(auto node : result){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
