// https://leetcode.com/problems/combinations/

class Solution {
public:

    void rec(int n,int k, vector<int> &v, vector<vector<int>>& ans){
        if(n==0){
            if(k==0) ans.push_back(v);
            return;
        }

        rec(n-1,k,v,ans);
        if(k){
            v.push_back(n);
            rec(n-1,k-1,v,ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        rec(n,k,v,ans);
        return ans;
    }
};
