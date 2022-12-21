// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/

class Solution {
public:
    vector<int>g[100100];
    vector<int>vis;

    void dfs(int node,vector<int>&res){
        vis[node]=1;
        res.push_back(node);
        for(auto &i:g[node]){
            if(!vis[i]) dfs(i,res);
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        for(auto &i:allowedSwaps){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vis.resize(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>res;
                dfs(i,res);
                map<int,int>mp;
                for(auto &j:res) mp[source[j]]++;
                for(auto &j:res){
                    if(mp[target[j]]>0) mp[target[j]]--;
                    else ans++;
                }
            }
        }
        return ans;
    }
};
