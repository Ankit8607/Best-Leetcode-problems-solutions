// https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    class node{
        public:
        int wend=0;
        string s;
        node *next[26];
        node(){
            for(int i=0;i<26;i++) next[i]=NULL;
        }  
    };

    void build(node *root,vector<string>& products){
        for(string &i:products){
            node *cur=root;
            for(char &ch:i){
                int t=ch-'a';
                if(cur->next[t]==NULL) cur->next[t]=new node();
                cur=cur->next[t];
            }
            cur->wend=1;
            cur->s=i;
        }
    }

    void dfs(node *cur,vector<string>&ans){
        if(ans.size()==3) return;
        if(cur->wend) ans.push_back(cur->s);

        for(int i=0;i<26;i++) if(cur->next[i]) dfs(cur->next[i],ans);
    }

    vector<string> query(node *root,string tar){
        node *cur=root;
        vector<string> ans;
        for(int i=0;i<tar.size();i++){
            int t=tar[i]-'a';
            if(cur->next[t]==NULL) return ans;
            cur=cur->next[t];
        }
        dfs(cur,ans);
        return ans;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        node *root=new node();
        build(root,products);
        vector<vector<string>>ans;
        for(int i=0;i<searchWord.length();i++){
            vector<string>res=query(root,searchWord.substr(0,i+1));
            ans.push_back(res);
        }
        return ans;
    }
};
