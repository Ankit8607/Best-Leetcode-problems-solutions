// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Solution {
public:
    vector<int>ans;

    void rec(int node,int par,vector<int>&cnt,string &labels,vector<vector<int>>&g) {
        int prevcnt=cnt[labels[node]-'a'];
        cnt[labels[node]-'a']=1;
        for(auto &i:g[node]){
            if(i!=par) rec(i,node,cnt,labels,g);
        }
        ans[node]=cnt[labels[node]-'a'];
        cnt[labels[node]-'a']+=prevcnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels){
        ans.resize(n,0);
        vector<vector<int>>g(n);
        vector<int>cnt(26,0);
        for(auto &i:edges){
            g[i[0]].push_back(i[1]);   
            g[i[1]].push_back(i[0]);   
        }
        rec(0,-1,cnt,labels,g);
        return ans;
    }
};
