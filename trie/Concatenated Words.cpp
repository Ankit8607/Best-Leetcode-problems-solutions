// https://leetcode.com/problems/concatenated-words/

class Solution {
public:
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }

    class node{
        public:
        int wend=0;
        node *arr[26];
        node(){
            wend=0;
            for(int i=0;i<26;i++) arr[i]=NULL;
        }  
    };

    bool rec(int level,string &s,node *cur,node *root){
        if(!cur) return 0;
        if(level==s.size()) return cur->wend;

        char ch=s[level];
        bool ans=rec(level+1,s,cur->arr[ch-'a'],root);
        if(cur->wend) ans|=rec(level+1,s,root->arr[ch-'a'],root);

        return ans;
    }

    void build(string s,node *cur){
        for(auto &i:s){
            int t=i-'a';
            if(cur->arr[t]==NULL) cur->arr[t]=new node();
            cur=cur->arr[t];
        }
        cur->wend=1;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        vector<string>ans;
        node *root=new node();
        for(auto &i:words){
            if(rec(0,i,root,root)) ans.push_back(i);
            build(i,root);
        }
        return ans;
    }
};
