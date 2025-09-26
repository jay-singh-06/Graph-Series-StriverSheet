#include<bits/stdc++.h>
using namespace std;

// we will use dfs traversal

// Small Optimizations
// We can make the code cleaner and more memory-efficient by:
// (a) Removing the vis array
// Right now, you're using a separate vis matrix. But since we already have grids, we can mark rotten oranges directly in grids instead of vis.
// This saves O(n × m) extra space.
// (b) Using a simpler queue structure
// Instead of storing { {row, col}, time }, we can store {row, col} and track time separately.

//t.c=(n*m)+0(4*n*m)=0(n*m),s.c=0(n*m)+0(n*m)=0(n*m)
int orangeRottens(vector<vector<int>>&grids){
    int n=grids.size();
    int m=grids[0].size();
    //{{row,col},time}
    queue<pair<pair<int,int>,int>>q;  //s.c=0(n*m)
    vector<vector<int>>vis(n,vector<int>(m,0)); //s.c=0(n*m)
    int cntFresh=0;

    //t.c=0(n*m)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grids[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
            else vis[i][j]=0;
            if(grids[i][j]==1) cntFresh++;
        }
    }
    int timeMax=0;
    //we take drow and dcol so that after adding we can get neighbours(left,right,up,down)
    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};
  int cnt=0;
  //t.c=0(4*n*m)
  while(!q.empty()){
    int r=q.front().first.first;
    int c=q.front().first.second;
    int t=q.front().second;
    timeMax=max(timeMax,t);
    q.pop();

    //moving through 4 neighbours
    for(int i=0;i<4;i++){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grids[nrow][ncol]==1){
            q.push({{nrow,ncol},t+1});
            vis[nrow][ncol]=2;
            cnt++;
        }
    }
  }
  if(cnt!=cntFresh) return -1; //that means some fresh orange remains
  return timeMax;
}

int main() {
    vector<vector<int>> grids = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int ans = orangeRottens(grids);

    cout << "Minimum time required: " << ans << endl;

    return 0;
}
