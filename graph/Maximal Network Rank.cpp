// https://leetcode.com/problems/maximal-network-rank/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>g(n,vector<int>(n,0));
        vector<int>arr(n,0);
        for(auto i:roads){
            g[i[0]][i[1]]=1;
            g[i[1]][i[0]]=1;
            arr[i[1]]++;
            arr[i[0]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,arr[i]+arr[j]-g[i][j]);
            }
        }
        return ans;
    }
};
