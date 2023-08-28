// https://leetcode.com/problems/process-restricted-friend-requests/

class Solution {
public:

    bool dfs(int val, int node,int par, vector<vector<int>>&g,set<pair<int,int>>&st){
        if(st.find({val,node})!=st.end() || st.find({node,val})!=st.end()) return 0;
        int ans=1;
        for(auto i: g[node]) if(i!=par) ans&=dfs(val,i,node,g,st);
        return ans;
    }

    bool check(int u,int v,int a,int b,vector<vector<int>>&g,set<pair<int,int>>&st){
        int ans=dfs(u,v,v,g,st);
        for(auto i: g[u]){
            if(i==a) continue;
            ans&=check(i,v,u,v,g,st);
        }
        return ans;
    }

    void assign(int node,int par,int col,vector<vector<int>>&g,vector<int>&comp){
        comp[node]=col;
        for(auto child: g[node]){
            if(child!=par) assign(child,node,col,g,comp);
        }
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        set<pair<int,int>>st;
        for(auto i : restrictions) st.insert({i[0],i[1]});
        vector<int>comp(n);
        for(int i=0;i<n;i++) comp[i]=i;
        vector<vector<int>>g(n);
        vector<bool>ans;
        for(auto i: requests){
            int u=i[0],v=i[1];
            if(st.find({u,v})!=st.end() || st.find({v,u})!=st.end()){
                ans.push_back(false);
                continue;
            }
            if(comp[u]==comp[v]){
                ans.push_back(true);
                continue;
            }

            if(check(u,v,u,v,g,st)){
                g[u].push_back(v);
                g[v].push_back(u);
                assign(u,v,comp[v],g,comp);
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};
