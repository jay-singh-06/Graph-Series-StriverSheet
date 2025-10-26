#include<bits/stdc++.h>
using namespace std;

class disjointSet{

vector<int>rank,parent,size;

public:

//constrcutor
disjointSet(int n){
rank.resize(n+1,0);
parent.resize(n+1);
size.resize(n+1);

for(int i=0;i<=n;i++){
    parent[i]=i;
    size[i]=1;
}
}

int findUParent(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUParent(parent[node]);
}

void unionBySize(int u,int v){
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
    vector<int>numOfIsland(int n,int m,vector<vector<int>>&operators){
        disjointSet ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        vector<int>ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];

            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            //if not visited 
            vis[row][col]=1;
            cnt++;

            vector<int> delRow={-1,0,1,0};
            vector<int> delCol={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==1){
                int nodeNo=row*m+col;
                int adjNodeNo=nrow*m+ncol;
                if(ds.findUParent(nodeNo)!=ds.findUParent(adjNodeNo)){
                    cnt--;
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};
    solution sol;
    vector<int> res = sol.numOfIsland(n, m, operators);

    for (int x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}