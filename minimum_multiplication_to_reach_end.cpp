#include<bits/stdc++.h>
using namespace std;

//we have given an array and with the multiplication of number on an array if we
//reach at end so we have to return step
//arr={2,5,7},start=3,end=75
//3
//3*2=6,3*5=15,3*7=21
//6*2=12,6*5=30,6*7=42,15*2=30,15*5=75(we got 75 which is end) step=2
//it is like djisktra's algorithm where we stores node,step/dist here we want ans under 100000 modulus


//t.c=0(n*100000) where n=arr.size,s.c=0(100000)
int minimumMultiplication(vector<int>arr,int start,int end){
queue<pair<int,int>>q;
q.push({start,0});//node=start,step=0
int mod=100000;
vector<int>dist(100000,INT_MAX); //here size should be mod of 100000 according to question
dist[start]=0;

while(!q.empty()){
    int node=q.front().first;
    int steps=q.front().second;
    q.pop();
    
    for(auto it:arr){
     int num=(it*node)%mod;
    if(steps+1<dist[num]){
     dist[num]=steps+1;
     if(num==end) return steps+1;
     q.push({num,steps+1});
    }
    }
}
return -1;
}

int main() {
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 75;
    cout << minimumMultiplication(arr, start, end) << endl;  // Expected output: 2
    return 0;
}
