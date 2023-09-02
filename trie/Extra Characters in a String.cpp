// https://leetcode.com/problems/extra-characters-in-a-string/?envType=daily-question&envId=2023-09-02

class Solution {
public:

    class node{
        public:
        node* arr[26]={NULL};
        int end=0;
    };

    void build(string s, node *head){
        node *cur=head;
        for(auto i:s){
            if(cur->arr[i-'a']==NULL) cur->arr[i-'a']=new node();
            cur=cur->arr[i-'a'];
        }
        cur->end=1;
    }

    void check(int ind,node *head,vector<int>&dp,string &s){
        node *cur=head;
        int start=ind;
        while(ind <s.size() and cur and cur->arr[s[ind]-'a']){
            cur=cur->arr[s[ind]-'a'];
            if(cur->end) dp[ind]=min(dp[ind],start==0?0:dp[start-1]);
            ind++;
        }
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        node *head=new node();
        for(auto i: dictionary) build(i,head);
        int n=s.size();
        vector<int>dp(n,1e9);
        for(int i=0;i<n;i++){
            check(i,head,dp,s);
            dp[i]=min(1+(i==0?0:dp[i-1]),dp[i]);
        }
        return dp[n-1];
    }
};
