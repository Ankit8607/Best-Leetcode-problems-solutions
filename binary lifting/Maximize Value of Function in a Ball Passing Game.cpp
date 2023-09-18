// https://leetcode.com/problems/maximize-value-of-function-in-a-ball-passing-game/description/

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& adj, long long k) {
        long long n = adj.size();
        long long res = 0;
        vector<vector<long long>> parent(n,vector<long long>(40,0));
        vector<vector<long long>> sum(n,vector<long long>(40,0));
        for(long long i = 0;i < n;i++) {
            parent[i][0] = adj[i];
            sum[i][0] = adj[i];
        }
        for(long long i = 1;i < 40;i++) {
            for(long long j = 0;j < n;j++) {
                parent[j][i] = parent[parent[j][i-1]][i-1];
                sum[j][i] = sum[j][i-1] + sum[parent[j][i-1]][i-1];
            }
        }
        for(long long i =0;i < n;i++) {
            long long curr_res = i;
            long long pos = i;
            long long shift = 1;
            for(long long j = 0;j < 40;j++) {
                if (j!=0)shift <<= 1;
                if (k & shift) {
                    curr_res += sum[pos][j];
                    pos = parent[pos][j];
                }
            }
            res = max(res,curr_res);
        }
        return res;
    }
};
