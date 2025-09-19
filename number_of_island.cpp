//also know as number of connected component
#include<bits/stdc++.h>
using namespace std;

void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&matrix){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    int n=matrix.size();
    int m=matrix[0].size();

    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        for(int delRow=-1;delRow<=1;delRow++){
            for(int delCol=-1;delCol<=1;delCol++){
                int nrow=row+delRow;//neighbour row=row number and move to 8 neighbour from -1 to 1
                int ncol=col+delCol; //neighbour col=col number and move to 8 neighbour from -1 to 1
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]=='1' && !vis[nrow][ncol]){
                  vis[nrow][ncol]=1;
                  q.push({nrow,ncol});
                }
            }
        }
    }
}

int numsIsland(vector<vector<char>>&matrix){
    if(matrix.empty()) return 0;
    int n=matrix.size();
    int m=matrix[0].size();

    //make n*m matrix to mark the visited char
    vector<vector<int>>vis(n,vector<int>(m,0));

    int cnt=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col] && matrix[row][col]=='1'){
                cnt++;
                bfs(row,col,vis,matrix);
            }
        }
    }
    return cnt;

}

int main() {
    vector<vector<char>> matrix = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands = " << numsIsland(matrix) << endl;
    return 0;
}