#include<bits/stdc++.h>
using namespace std;

//t.c of finURPath=0(4alpha )=which is lesser than 0(constant) same for 
//unionBYRank and UNIONBYSize=0(4alpha)

class disjointSet{
vector<int>rank,parent,size;

public:
//constructor
disjointSet(int n){
    rank.resize(n+1,0); //rank vector size=n initialise with 0
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
}

//function to find ultimate parent
int findUParent(int node){
    if(node==parent[node]) return node; //if a node itself is a parent (starting)
    return parent[node]=findUParent(parent[node]);
}

//rank=level 
void UnionByRank(int u,int v){
int ulp_u=findUParent(u); //ultimate parent of u is the last parent of u
int ulp_v=findUParent(v); //ultimate parent of v is the last parent of v
if(ulp_u==ulp_v) return;

//if rank of u is smaller than rank of v then smaller will connected to larger
if(rank[ulp_u]<rank[ulp_v]){
    parent[ulp_u]=ulp_v; //then u will be parent of v
}

//if rank of v is smaller than rank of u then v will be connect to u
else if(rank[ulp_v]<rank[ulp_u]){
    parent[ulp_v]=ulp_u;
}
//if rank of u and v are equal then take anybody parent
else{
 parent[ulp_v]=parent[ulp_u]; //I here take v as a parent of u u can reverse also
 rank[ulp_u]++;
}
}

//size=no of nodes
void  unionBySize(int u,int v){
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

int main(){
    disjointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    
    //if you want to see that 3 and 7 comes in same component so you have to
    //check 3 and 7 ultimate parents are same o r not
    if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"same"<<endl;
    }
    cout<<"not same"<<endl;

    return 0;
}