// https://leetcode.com/problems/search-a-2d-matrix/submissions/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m=mat[0].size();
        int lo=0,hi=n-1,ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(mat[mid][0]<=target){
                lo=mid+1;
                ans=mid;
            }
            else hi=mid-1;
        }
        auto it=lower_bound(mat[ans].begin(),mat[ans].end(),target)-mat[ans].begin();
        if(it<m and mat[ans][it]==target) return 1;
        return 0;
    }
};
