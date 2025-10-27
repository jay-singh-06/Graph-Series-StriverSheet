#include<bits/stdc++.h>
using namespace std;

class disjoint{
    public:
    vector<int>parent,size;

    disjoint(int n){
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

class Solution{

    public:
    int largestIsland(vector<vector<int>>&grid){
        int n=grid.size();
        disjoint ds(n*n);

        //step 1=connect all 1 with neighbours

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                vector<int>delRow={-1,0,1,0};
                vector<int>delCol={0,-1,0,1};

                for(int i=0;i<4;i++){
                    int nrow=row+delRow[i];
                    int ncol=col+delCol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                     int nodeNo=row*n+col;
                     int adjNodeNo=nrow*n+ncol;
                     ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }

        //step 2=convert 0 to 1 and check for greater size of 1 
        int maxSum=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                vector<int>delRow={-1,0,1,0};
                vector<int>delCol={0,-1,0,1};
                set<int>components;

                for(int i=0;i<4;i++){
                    int nrow=row+delRow[i];
                    int ncol=col+delCol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                    components.insert(ds.findUParent(nrow*n+ncol));
                    }
                }
                int totalSize=1;
                for(auto it:components){
                    totalSize+=ds.size[it];
                }
                maxSum=max(maxSum,totalSize);
            }
        }
         // Step 3: Handle case where grid has all 1s
       for(int cellNo=0;cellNo<n*n;cellNo++){
        maxSum=max(maxSum,ds.size[ds.findUParent(cellNo)]);
       }
       return maxSum;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}
    };

    Solution sol;
    int result = sol.largestIsland(grid);

    cout << "Largest island size: " << result << endl;

    return 0;
}