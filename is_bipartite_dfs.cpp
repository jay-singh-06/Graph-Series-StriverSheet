#include<bits/stdc++.h>
using namespace std;

bool isdfs(int node,int col,vector<int>&color,vector<vector<int>>&graph){
    color[node]=col;//select any node and color with 0 as calling col=0
    
    for(auto it:graph[node]){  //iterating their adjacent neighbour
        if(color[it]==-1){
            if(isdfs(it,!col,color,graph)==false) return false;//! will change 0 to 1 and 1 to 0
        }
         //if it is coloured
        else if(color[it]==col) return false;  //if colour of adjacent node is same return false
    }
    return true;
}

bool isBipartite(vector<vector<int>>graph){
    int v=graph.size();
    vector<int>color(v);  //creating a vector of name color and size v
    for(int i=0;i<v;i++) color[i]=-1;   //intialise the vector with -1

    for(int i=0;i<v;i++){
        if(color[i]==-1){    //if it is not coloured then call dfs
            if(isdfs(i,0,color,graph)==false) return false; //if dfs returns false then it is bipartite
        }
    }
    return true;
}

int main() {
    // Example graph (adjacency list)
    vector<vector<int>> graph = {
        {1, 3}, // node 0 connected to 1,3
        {0, 2}, // node 1 connected to 0,2
        {1, 3}, // node 2 connected to 1,3
        {0, 2}  // node 3 connected to 0,2
    };

    if (isBipartite(graph))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is NOT Bipartite\n";

    return 0;
}