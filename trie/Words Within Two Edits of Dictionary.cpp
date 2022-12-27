// https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/

class Solution {
public:
    class node{
        public:
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
        }
    }

    int dfs(int level,node *root,string &tar,int cnt){
        if(cnt>2) return 0;
        if(level==tar.size()) return 1;

        int ans=0;
        for(int i=0;i<26;i++){
            if(root->next[i]){
                if(i!=(tar[level]-'a')) ans|=dfs(level+1,root->next[i],tar,cnt+1);
                else ans|=dfs(level+1,root->next[i],tar,cnt);
            }
        }
        return ans;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& products) {        
        node *root=new node();
        build(root,products);
        vector<string>ans;
        for(string &s:queries) {
            if(dfs(0,root,s,0))
                ans.push_back(s);
        }
        return ans;
    }
};
