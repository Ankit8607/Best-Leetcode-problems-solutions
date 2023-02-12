// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

class Solution {
public:
    long long ans=0;
    int rec(int node,int par, vector<vector<int>> &g,int &seats){
        int total=1;
        for(auto &i:g[node]){
            if(i==par) continue;
            int t=rec(i,node,g,seats);
            ans+=ceil(1.0*t/seats);
            total+=t;
        }
        return total;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>>g(n);
        for(auto &i:roads){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        rec(0,-1,g,seats);
        return ans;
    }
};
