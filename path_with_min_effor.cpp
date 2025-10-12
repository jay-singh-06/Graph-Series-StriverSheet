#include<bits/stdc++.h>
using namespace std;

//int this quetion we hsve given a matrix like
//1   2   2   so we have to start from(0,0)=1 and destination is (2,2)=(5)
//3   8   2   and we have to check possible path ex=if we start from (0,0) and 
//5   3   5   go to right end and then down ->|1-2|=1,|2-2|=0,|2-2|=0,|2-5|=3 max effort=3
//this show that we have to check possible path which start from (0,0) and (2,2) in which 
//we have to subtract adjacent cell and take abs of it and take max of effort along that path

//t.c=0(n*m*log(n*m)) -log n*m for pq,s.c=0(n*m) for pq,dis

int minimumEffortPath(vector<vector<int>>height){
    int n=height.size();
    int m=height[0].size();

    //priority queue with min heap(minimum difference will be on top)
    //{diff,{r,c}}
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;
    
  // 2d distnace vector with value infinite
    vector<vector<int>>dis(n,vector<int>(m,1e9));
    dis[0][0]=0;//o base indexing
    pq.push({0,{0,0}});

    //delrow and delrow is for changing of row and col while iterating their 4 neighbours
    vector<int>delRow={-1,0,1,0};
    vector<int>delCol={0,1,0,-1};

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int diff=it.first;
        int row=it.second.first;
        int col=it.second.second;

        if(row==n-1 && col==m-1) return diff;

        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                //newEffor=maximum of absolute of substraction of current row col and neighbour row col and diff 
                int newEffort=max(abs(height[row][col]-height[nrow][ncol]),diff);
                if(newEffort<dis[nrow][ncol]){ //if our newEffort is min then update dis of row col
                  dis[nrow][ncol]=newEffort;
                  pq.push({newEffort,{nrow,ncol}}); //diff,row,col of neighbour
                }
            }
        }
    }
    return 0;//unreachable
}

int main() {
    vector<vector<int>> heights = {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };

    cout << "Minimum Effort Path: " << minimumEffortPath(heights) << endl;
    // Expected output: 2

    return 0;
}
