#include<bits/stdc++.h>
using namespace std;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());

        if(st.find(endWord) == st.end()) return {};
        
        queue<vector<string>>q; //we want queue in list form
        q.push({beginWord});
        vector<string>visited;
        visited.push_back(beginWord);
        int level=0;
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>vec=q.front();
            q.pop();
            //erase all words that has been visited

           // ex=bat -level 1
           //ex=bat,pat -level 2 (word>level 1)
           //ex=bat,bot -level 2
           //ex=bat,pat,pot -level 3 (word>level 2)
            if(vec.size()>level){
                level++;

                for(auto it:visited){
                    st.erase(it);
                }
                visited.clear();
            }
            string word=vec.back();//selecting the element which insert recently
             
             if(word==endWord){
             //the first sequenece where we reach end

             if(ans.size()==0){
                ans.push_back(vec);
             }
             else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
             }
             }
            for(int i=0;i<word.size();i++){
                char original =word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        visited.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }

    int main() {
    
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);

    cout << "All shortest transformation sequences:\n";
    for (auto &path : res) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i + 1 == path.size() ? "" : " -> ");
        }
        cout << "\n";
    }

    return 0;
}
