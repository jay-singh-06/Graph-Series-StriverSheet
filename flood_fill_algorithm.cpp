#include<bits/stdc++.h>
using namespace std;

//sr(starting row)=2 sc(starting column)=0 newcolor=3 are given
// we go at third row and firrst column and whichever number will be like 2 is there
//so neighbour of 2(up,left,down,right) if it is 2 then change it to newcolor(3)


//t.c=0(4*n*m)=0(n*m),s.c=0(n*m) for copy +0(n*m) for recursion and for del row and del col=0(n*m)

void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>&image,int color,int delRow[],
int delCol[],int iniColor){
    ans[row][col]=color;
    int n=image.size();
    int m=image[0].size();

    for(int i=0;i<4;i++){
        int nrow=row+delRow[i];  //neighbour row
        int ncol=col+delCol[i];  //neighbour column

        //if nrow and ncol is in range and also if neighbour row and col is inicolor and it is
        // not newcolor

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=color){
            dfs(nrow,ncol,ans,image,color,delRow,delCol,iniColor);
        }
    }
}

vector<vector<int>>floodFill(vector<vector<int>> &image,int sr,int sc,int color){
    int iniColor=image[sr][sc];  //starting row and starting col number
    vector<vector<int>>ans=image; //we generate copy of image so that we not disturb interviewers data

    int delRow[]={-1,0,+1,0}; //it is change in row if we go up downleft right
    int delCol[]={0,+1,0,-1};  //it is change in col if we go up downleft right

    dfs(sr,sc,ans,image,color,delRow,delCol,iniColor);
    return ans;
}

int main() {
    // Input image matrix
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;      // starting row
    int sc = 1;      // starting column
    int color = 2;   // new color to fill

    vector<vector<int>> result = floodFill(image, sr, sc, color);

    cout << "Resultant Image after Flood Fill:\n";
    for (auto row : result) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }

    return 0;
}
