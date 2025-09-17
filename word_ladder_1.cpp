#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord,string endWord,vector<string>&wordList){
    //word,steps
  queue<pair<string,int>>q;

  //initializing our queue with putting beginWord and step is initialisized at 1
  q.push({beginWord,1});

  unordered_set<string>st(wordList.begin(),wordList.end());

  if(st.find(endWord)==st.end()) return 0; //if endWord is not found then return 0

  while(!q.empty()){
    string word=q.front().first;
    int steps=q.front().second;
    q.pop();

    if(word==endWord) return steps;

    //ex=hit
    for(int i=0;i<word.size();i++){
        //h
        char original=word[i];
        //changing first letter from a to z and checking is any word found

        for(char ch='a';ch<='z';ch++){
            word[i]=ch;
          //ait 
          //bit
          //cit
          
          //zit

           //if it exist?
            if(st.find(word)!=st.end()){
                st.erase(word);//deleting word if it is found so it does create dupliacate
                q.push({word,steps+1}); //insert that word in queue and increment step to 1
            }
        }
        word[i]=original;
    }
  }
  return 0; // no word found return 0
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = ladderLength(beginWord, endWord, wordList);
    if(result == 0)
        cout << "No transformation sequence exists." << endl;
    else
        cout << "Shortest transformation sequence length: " << result << endl;

    return 0;
}
