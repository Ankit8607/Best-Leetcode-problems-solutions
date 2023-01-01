// https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        int pre[n+1];
        pre[0]=0;
        for(int i=0;i<n;i++) pre[i+1]=pre[i]^arr[i];
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(pre[1+queries[i][1]]^pre[queries[i][0]]);
        }
        return ans;
    }
};
