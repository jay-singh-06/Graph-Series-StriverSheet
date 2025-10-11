#include<bits/stdc++.h>
using namespace std;

//it is same like print shortes path approach but here we will given as src=0,1
//destination as 2,2 so here for src 0,1 shows that row=0,col=2 so we have to given a binary table
//and we have to move cell to cell and find shortest distance between  src and destination

// so approach will be same like print shortest path we will not take pq because here
//edge weight is unit so if we take pq it wil move in constant distance so pq will give min heap
//so we use queue (dis,{row,col}) in this manner and take dist vector in binary box n*m size
// and initialise as INT_MAX(infinity) after everything is same dist[node]+edwt<dis then update it

//t.c=0(n*m*8)=0(n*m),s.c=0(n*m) for distance+0(n+m) for queue=0(n+m)

int shortestPathBinaryMatrix(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    pair<int,int>src{0,0}; //starting point
    pair<int,int>dest{n-1,n-1}; //destination point

    //if start or end is blocked
    if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

    //edge case
    if(src==dest) return 1;

    queue<pair<int,pair<int,int>>>q; //{dis,{row,col}}
    vector<vector<int>>dis(n,vector<int>(m,1e9));
    dis[src.first][src.second]=1;//indexing of dis starts from 1
    q.push({1,{src.first,src.second}});

    //for 8 neigbours we use delRow,delRow
    vector<int>delRow={-1,-1,-1,0,0,1,1,1};
    vector<int>delCol={-1,0,1,-1,1,-1,0,1};

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int d=it.first;
        int r=it.second.first;
        int c=it.second.second;

        //ietrting through their 8 neighbours(including diagonal)
        for(int i=0;i<8;i++){
            int nrow=r+delRow[i];
            int ncol=c+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 
            && d+1<dis[nrow][ncol]){
                dis[nrow][ncol]=d+1;
                if(nrow==dest.first && ncol==dest.second) return dis[nrow][ncol];
                q.push({d+1,{nrow,ncol}});
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = {
        {0,1,0},
        {1,0,0},
        {1,1,0}
    };

    int ans = shortestPathBinaryMatrix(grid);

    if (ans != -1) cout << "Shortest Path Length: " << ans << endl;
    else cout << "No path exists" << endl;

    return 0;
}