#include<bits/stdc++.h>
using namespace std;

//approach is simpple first find 1 and mark their 4 neighbour 1 in dist array and from 1 
//we do same this time distance wwill be 2 in dist array

vector<vector<int>>updateMatrix(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                vis[i][j]=1;
            }else vis[i][j]=0;
        }
    }

    vector<int>delRow={-1,0,+1,0};
    vector<int>delCol={0,+1,0,-1};

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        dis[row][col]=steps;

        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},steps+1});
            }
        }
    }
    return dis;
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> ans = updateMatrix(mat);

    cout << "Updated Matrix:\n";
    for (auto row : ans) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }
    return 0;
}