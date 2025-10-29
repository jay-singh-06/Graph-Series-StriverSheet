#include<bits/stdc++.h>
using namespace std;

class Solution{

    private:

    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
     vis[node]=1;
     for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
     }
     st.push(node);
    }

    private:
    void dfs3(int node,vector<int>&vis,vector<vector<int>>&adjT){
        vis[node]=1;
        for(auto it:adjT[node]){
        if(!vis[it]){
         dfs3(it,vis,adjT);
        }
    }
    }

    public:
int strongly_connected(int v,vector<vector<int>>&adj){

    vector<int>vis(v,0);
    stack<int>st;

    //step 1 do normal dfs and put in stack
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }


    //step 2= reverse the graph 
    vector<vector<int>>adjT(v);//traspose of adjacent/opposite
    for(int i=0;i<v;i++){
        vis[i]=0;
    for(auto it:adj[i]){
        //i->it
        //it->i
        adjT[it].push_back(i);
    }
    }

    //step 3 =put all stack elment and apply dfs if it is not visited yet then increment scc to 1
    int scc=0;//initialisize strong component to 0

    while(!st.empty()){
        int node=st.top();
        st.pop();

        if(!vis[node]){
            scc++;
            dfs3(node,vis,adjT);
        }
    }
    return scc;
}
};

int main() {
    int v = 5;
    vector<vector<int>> adj(v);

    adj[0] = {2, 3};
    adj[1] = {0};
    adj[2] = {1};
    adj[3] = {4};

    Solution obj;
    cout << "Number of Strongly Connected Components: "
         << obj.strongly_connected(v, adj) << endl;

    return 0;
}