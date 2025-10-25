
#include<bits/stdc++.h>
using namespace std;

class disjoint{
    vector<int>parent,size;

    public:

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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        //step 1 =connecting the nodes and making the disjoint sets and making the ultimate parent

        int n=accounts.size();
        disjoint ds(n);

        unordered_map<string,int>mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                //if mail is not found in map then add it with node =its row no
                if(mapMailNode.find(mail)==mapMailNode.end()){
                mapMailNode[mail]=i;
                }
                //if mail is found in map already then union it with previous mail index
                else{
                ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }

        //step 2= merging the mails according to their disjoint set data structure

        vector<vector<string>>mergeMail(n);
        for(auto it:mapMailNode){
            string mail=it.first;
            int node=ds.findUParent(it.second);
            mergeMail[node].push_back(mail);
        }

        //step 3=rearranging them in list of list first name then mail

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]); //it will insert name first 
            for(auto it:mergeMail[i]){
                temp.push_back(it);//it will add all mails after name
            }
            ans.push_back(temp);
         }
         return ans;
    }
};

int main() {
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };

    Solution sol;
    vector<vector<string>> mergedAccounts = sol.accountsMerge(accounts);

    // Print the merged accounts
    for (auto &acc : mergedAccounts) {
        for (auto &s : acc) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}